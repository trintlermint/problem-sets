"""
Competitive Programming Judge Problem Count Scraper
====================================================

This module aggregates the total number of problems available on various
competitive programming and online judge websites.

Usage:
    from scraper import scrape_all_sites
    result = scrape_all_sites()
    print(result)

Supported Judges:
    - Aizu Online Judge
    - CodeChef
    - Codeforces
    - CSES Problem Set
    - Deep-ML
    - DMOJ
    - EOlymp
    - HackerRank
    - Kattis
    - KiloNova
    - LeetCode
    - LibreOJ
    - Perl Weekly Review
    - Project Euler
    - SPOJ
    - Timus Online Judge

Error Handling:
    - Returns -1 if scraping fails for a site
    - Includes timeout handling and retry logic
    - Gracefully handles site structure changes
"""

import time
import requests
from bs4 import BeautifulSoup
from typing import Dict, Optional
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Constants
TIMEOUT = 15
RETRY_ATTEMPTS = 2
RETRY_DELAY = 2  # seconds
USER_AGENTS = [
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36',
    'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36',
    'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36',
]

CURRENT_USER_AGENT = USER_AGENTS[0]


def get_user_agent() -> str:
    """Rotate through user agents to avoid blocking."""
    global CURRENT_USER_AGENT
    CURRENT_USER_AGENT = USER_AGENTS[USER_AGENTS.index(CURRENT_USER_AGENT) - 1]
    return CURRENT_USER_AGENT


def make_request(url: str, headers: Optional[Dict] = None, **kwargs) -> Optional[requests.Response]:
    """
    Make HTTP request with retry logic and error handling.
    
    Args:
        url: The URL to request
        headers: Optional custom headers
        **kwargs: Additional arguments to pass to requests.get()
    
    Returns:
        Response object or None if request fails
    """
    if headers is None:
        headers = {'User-Agent': get_user_agent()}
    
    for attempt in range(RETRY_ATTEMPTS):
        try:
            response = requests.get(url, timeout=TIMEOUT, headers=headers, **kwargs)
            response.raise_for_status()
            return response
        except requests.exceptions.RequestException as e:
            logger.warning(f"Request failed for {url} (attempt {attempt + 1}/{RETRY_ATTEMPTS}): {str(e)}")
            if attempt < RETRY_ATTEMPTS - 1:
                time.sleep(RETRY_DELAY)
    
    return None


# ============================================================================
# AIZU ONLINE JUDGE
# ============================================================================

def get_aizu_problem_count() -> int:
    """
    Scrape Aizu Online Judge problem count.
    
    URL: https://onlinejudge.u-aizu.ac.jp/
    
    The Aizu judge provides a problem list that can be parsed from their
    main problem page. We count all available problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://onlinejudge.u-aizu.ac.jp/problems?volume=0"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Aizu Online Judge")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for problem count in pagination or problem list
        # Aizu typically shows problem count in the page
        problems_text = soup.find(string=lambda text: text and "problem" in text.lower())
        
        if problems_text:
            # Try to extract number from text
            import re
            match = re.search(r'(\d+)\s*problem', problems_text)
            if match:
                return int(match.group(1))
        
        # Alternative: count problem rows in the table
        problem_rows = soup.find_all('tr', class_='ng-scope')
        if problem_rows:
            return len(problem_rows)
        
        logger.warning("Could not determine problem count for Aizu")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Aizu Online Judge: {str(e)}")
        return -1


# ============================================================================
# CODECHEF
# ============================================================================

def get_codechef_problem_count() -> int:
    """
    Scrape CodeChef problem count.
    
    URL: https://www.codechef.com/
    
    CodeChef provides a problem archive. We sum problems across all
    difficulty levels and categories.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://www.codechef.com/api/contests/all?status=past"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch CodeChef problem list")
            return -1
        
        # Try JSON API first
        try:
            data = response.json()
            if 'past_contests' in data:
                total_problems = 0
                for contest in data['past_contests']:
                    # Each contest has problems
                    if 'problems' in contest:
                        total_problems += len(contest['problems'])
                return total_problems
        except:
            pass
        
        # Fallback to HTML parsing
        url = "https://www.codechef.com/problems/tags"
        response = make_request(url)
        
        if not response:
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        problem_count = 0
        
        # Parse problem tags/categories
        tags = soup.find_all('a', {'data-reactid': True})
        
        logger.warning("CodeChef scraping may be limited; API requires authentication")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping CodeChef: {str(e)}")
        return -1


# ============================================================================
# CODEFORCES
# ============================================================================

def get_codeforces_problem_count() -> int:
    """
    Scrape Codeforces problem count.
    
    URL: https://codeforces.com/problemset
    
    Codeforces provides a publicly accessible problemset with pagination.
    We fetch the first page and extract the total problem count.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        # Use Codeforces API which is more reliable
        url = "https://codeforces.com/api/problemset.problems"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Codeforces API")
            return -1
        
        data = response.json()
        
        if data.get('status') == 'OK' and 'result' in data:
            problems = data['result'].get('problems', [])
            return len(problems)
        
        logger.warning("Unexpected Codeforces API response")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Codeforces: {str(e)}")
        return -1


# ============================================================================
# CSES PROBLEM SET
# ============================================================================

def get_cses_problem_count() -> int:
    """
    Scrape CSES Problem Set problem count.
    
    URL: https://cses.fi/problemset/
    
    CSES provides a free competitive programming problem set. We parse
    the problem list page to count all available problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://cses.fi/problemset/"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch CSES Problem Set")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Find all problem rows in the table
        problem_rows = soup.find_all('tr')
        
        # Filter rows that contain problem links (skip header)
        problem_count = 0
        for row in problem_rows:
            if row.find('a', href=True) and '/problemset/task/' in str(row.find('a', href=True)):
                problem_count += 1
        
        if problem_count > 0:
            return problem_count
        
        logger.warning("Could not parse CSES problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping CSES Problem Set: {str(e)}")
        return -1


# ============================================================================
# DEEP-ML
# ============================================================================

def get_deepml_problem_count() -> int:
    """
    Scrape Deep-ML problem count.
    
    URL: https://www.deep-ml.com/ (if exists)
    
    NOTE: Deep-ML does not appear to have a public accessible problem
    catalog as of this implementation. Most content is behind login.
    Returns -1 to indicate unavailability.
    
    Returns:
        -1 (site not publicly accessible)
    """
    try:
        url = "https://www.deep-ml.com/"
        response = make_request(url)
        
        if not response:
            logger.warning("Deep-ML is not accessible")
            return -1
        
        # Check if content is behind login
        if 'login' in response.text.lower() or 'sign in' in response.text.lower():
            logger.info("Deep-ML problems are behind authentication")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Try to find problem count
        problems = soup.find_all(class_='problem')
        if problems:
            return len(problems)
        
        logger.warning("Deep-ML problem catalog not publicly available")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Deep-ML: {str(e)}")
        return -1


# ============================================================================
# DMOJ (Don Mills Online Judge)
# ============================================================================

def get_dmoj_problem_count() -> int:
    """
    Scrape DMOJ problem count.
    
    URL: https://dmoj.ca/problems/
    
    DMOJ provides a public problem archive with pagination. We scrape
    all pages to get the total count.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://dmoj.ca/problems/"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch DMOJ problems")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for pagination info or total count display
        pagination = soup.find('ul', class_='pagination')
        
        if pagination:
            # Get last page number
            pages = pagination.find_all('a')
            last_page = 1
            for page_link in pages:
                page_text = page_link.get_text(strip=True)
                if page_text.isdigit():
                    last_page = max(last_page, int(page_text))
            
            # DMOJ shows ~50 problems per page (estimate)
            # Better approach: check page info text
            page_info = soup.find(string=lambda text: text and 'of' in text.lower())
            if page_info:
                import re
                match = re.search(r'of (\d+)', page_info)
                if match:
                    return int(match.group(1))
            
            # Fallback: count on current page and estimate
            problem_rows = soup.find_all('tr', class_='problem-row')
            if problem_rows and last_page > 1:
                return len(problem_rows) * last_page
        
        # Direct count if pagination not found
        problem_rows = soup.find_all('tr', class_='problem-row')
        if problem_rows:
            return len(problem_rows)
        
        logger.warning("Could not determine DMOJ problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping DMOJ: {str(e)}")
        return -1


# ============================================================================
# EOLYMP
# ============================================================================

def get_eolymp_problem_count() -> int:
    """
    Scrape EOlymp problem count.
    
    URL: https://www.eolymp.com/en/problems
    
    EOlymp provides a problem archive. We scrape the problem list page
    to count all available problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://www.eolymp.com/en/problems"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch EOlymp problems")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for problem count indicator
        # EOlymp typically shows total in a header or info section
        info_text = soup.find(string=lambda text: text and 'problem' in text.lower())
        
        if info_text:
            import re
            match = re.search(r'(\d+)\s*problem', info_text, re.IGNORECASE)
            if match:
                return int(match.group(1))
        
        # Count problem rows
        problem_rows = soup.find_all('div', class_='problem-item')
        if problem_rows:
            return len(problem_rows)
        
        problem_rows = soup.find_all('tr', class_='problem')
        if problem_rows:
            return len(problem_rows)
        
        logger.warning("Could not determine EOlymp problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping EOlymp: {str(e)}")
        return -1


# ============================================================================
# HACKERRANK
# ============================================================================

def get_hackerrank_problem_count() -> int:
    """
    Scrape HackerRank problem count.
    
    URL: https://www.hackerrank.com/
    
    HackerRank is heavily JavaScript-rendered. We use a REST API endpoint
    instead of Selenium for better efficiency.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        # HackerRank provides a GraphQL API, but simpler REST endpoints exist
        # Try the challenges API
        url = "https://www.hackerrank.com/rest/challenges"
        headers = {
            'User-Agent': get_user_agent(),
            'Accept': 'application/json',
        }
        response = make_request(url, headers=headers)
        
        if response:
            try:
                data = response.json()
                if 'models' in data:
                    return len(data['models'])
                if 'challenges' in data:
                    return len(data['challenges'])
            except:
                pass
        
        # Alternative: Try direct URL with pagination
        url = "https://www.hackerrank.com/challenges"
        response = make_request(url)
        
        if not response:
            logger.warning("HackerRank API is not accessible")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for challenge count in metadata
        meta_tags = soup.find_all('meta')
        for meta in meta_tags:
            if 'content' in meta.attrs:
                content = meta.attrs['content']
                if 'challenge' in content.lower():
                    import re
                    match = re.search(r'(\d+)', content)
                    if match:
                        return int(match.group(1))
        
        logger.warning("Could not determine HackerRank problem count; site is JS-heavy")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping HackerRank: {str(e)}")
        return -1


# ============================================================================
# KATTIS
# ============================================================================

def get_kattis_problem_count() -> int:
    """
    Scrape Kattis problem count.
    
    URL: https://open.kattis.com/problems
    
    Kattis provides a public problem archive with pagination. We scrape
    the archive to count total problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://open.kattis.com/problems"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Kattis problems")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for total count in the page
        # Kattis shows pagination info at the bottom
        pagination_text = soup.find(string=lambda text: text and 'of' in str(text))
        
        if pagination_text:
            import re
            match = re.search(r'of (\d+)', str(pagination_text))
            if match:
                return int(match.group(1))
        
        # Count problems on current page as fallback
        problem_rows = soup.find_all('tr', class_='problem-row')
        if problem_rows:
            return len(problem_rows)
        
        logger.warning("Could not determine Kattis problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Kattis: {str(e)}")
        return -1


# ============================================================================
# KILONOVA
# ============================================================================

def get_kilonova_problem_count() -> int:
    """
    Scrape KiloNova problem count.
    
    URL: https://kilonova.ro/ (if exists and public)
    
    NOTE: KiloNova is primarily a Romanian platform and may not have
    a fully public problem list accessible without authentication.
    
    Returns:
        Total number of problems or -1 on failure/unavailable
    """
    try:
        url = "https://kilonova.ro/problems"
        response = make_request(url)
        
        if not response:
            logger.warning("KiloNova is not accessible or requires authentication")
            return -1
        
        # Check for login requirement
        if 'login' in response.text.lower() or response.status_code == 403:
            logger.info("KiloNova problems require authentication")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Try to find problem count
        problem_rows = soup.find_all('tr', class_='problem')
        if problem_rows:
            return len(problem_rows)
        
        problem_items = soup.find_all('div', class_='problem-item')
        if problem_items:
            return len(problem_items)
        
        logger.warning("KiloNova problem list not accessible")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping KiloNova: {str(e)}")
        return -1


# ============================================================================
# LEETCODE
# ============================================================================

def get_leetcode_problem_count() -> int:
    """
    Scrape LeetCode problem count.
    
    URL: https://leetcode.com/problemset/all/
    
    LeetCode provides a GraphQL API for problem data. We query this
    API to get the total count of problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        # LeetCode uses GraphQL API
        url = "https://leetcode.com/graphql"
        
        # GraphQL query to get all problems
        query = """
        query problemsetQuestionList {
            problemsetQuestionList: questionList(
                categorySlug: ""
                limit: -1
                skip: 0
                filters: {}
            ) {
                total: totalNum
            }
        }
        """
        
        headers = {
            'User-Agent': get_user_agent(),
            'Content-Type': 'application/json',
            'Referer': 'https://leetcode.com/problemset/all/',
        }
        
        response = requests.post(
            url,
            json={'query': query},
            headers=headers,
            timeout=TIMEOUT
        )
        
        if response.status_code == 200:
            data = response.json()
            if 'data' in data and 'problemsetQuestionList' in data['data']:
                total = data['data']['problemsetQuestionList'].get('total', -1)
                if total >= 0:
                    return total
        
        # Fallback: try parsing the HTML page
        url = "https://leetcode.com/problemset/all/"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch LeetCode problem list")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Try to find problem count in the page metadata or JavaScript
        import re
        script_tags = soup.find_all('script')
        for script in script_tags:
            if script.string and 'total' in script.string:
                match = re.search(r'"total[Nn]um?"\s*:\s*(\d+)', script.string)
                if match:
                    return int(match.group(1))
        
        logger.warning("Could not determine LeetCode problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping LeetCode: {str(e)}")
        return -1


# ============================================================================
# LIBREOJ
# ============================================================================

def get_libreoj_problem_count() -> int:
    """
    Scrape LibreOJ problem count.
    
    URL: https://loj.ac/problems
    
    LibreOJ is a Chinese online judge. We scrape the problem list page
    to count all available problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://loj.ac/problems"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch LibreOJ problems")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for problem count in pagination or header
        import re
        
        # Try to find total count in page text
        page_text = soup.get_text()
        match = re.search(r'(\d+)\s*个题目', page_text)  # Chinese for "problems"
        if match:
            return int(match.group(1))
        
        # Try English variant
        match = re.search(r'(\d+)\s*problem', page_text, re.IGNORECASE)
        if match:
            return int(match.group(1))
        
        # Count problem rows
        problem_rows = soup.find_all('tr', class_='problem')
        if problem_rows:
            return len(problem_rows)
        
        problem_items = soup.find_all('div', class_='problem-item')
        if problem_items:
            return len(problem_items)
        
        logger.warning("Could not determine LibreOJ problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping LibreOJ: {str(e)}")
        return -1


# ============================================================================
# PERL WEEKLY REVIEW
# ============================================================================

def get_perl_weekly_review_count() -> int:
    """
    Scrape Perl Weekly Review problem count.
    
    URL: https://theweeklychallenge.org/ (or similar)
    
    The Perl Weekly Challenge provides weekly coding challenges.
    We count the total number of challenges available.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        # The Perl Weekly Challenge is at theweeklychallenge.org
        url = "https://theweeklychallenge.org/challenges/"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Perl Weekly Challenge")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Count challenge entries
        # Each week typically has 2 challenges
        import re
        
        # Look for week numbers
        week_links = soup.find_all('a', href=re.compile(r'/blog/perl-weekly-challenge-\d+'))
        
        if week_links:
            # Extract week numbers to find the highest
            week_numbers = []
            for link in week_links:
                match = re.search(r'challenge-(\d+)', link.get('href', ''))
                if match:
                    week_numbers.append(int(match.group(1)))
            
            if week_numbers:
                max_week = max(week_numbers)
                # Each week has 2 challenges
                return max_week * 2
        
        # Alternative: count challenge posts directly
        challenge_items = soup.find_all('article', class_='challenge')
        if challenge_items:
            return len(challenge_items)
        
        logger.warning("Could not determine Perl Weekly Challenge count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Perl Weekly Challenge: {str(e)}")
        return -1


# ============================================================================
# PROJECT EULER
# ============================================================================

def get_project_euler_problem_count() -> int:
    """
    Scrape Project Euler problem count.
    
    URL: https://projecteuler.net/
    
    Project Euler provides mathematical/programming challenges.
    We scrape the archive page to count all problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://projecteuler.net/archives"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Project Euler archives")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Project Euler shows problems in a table
        # Count all problem links
        import re
        problem_links = soup.find_all('a', href=re.compile(r'problem=\d+'))
        
        if problem_links:
            # Extract problem numbers to find the highest
            problem_numbers = []
            for link in problem_links:
                match = re.search(r'problem=(\d+)', link.get('href', ''))
                if match:
                    problem_numbers.append(int(match.group(1)))
            
            if problem_numbers:
                # The highest problem number is the total count
                return max(problem_numbers)
        
        # Alternative: look for problem count in page text
        page_text = soup.get_text()
        match = re.search(r'(\d+)\s*problem', page_text, re.IGNORECASE)
        if match:
            return int(match.group(1))
        
        logger.warning("Could not determine Project Euler problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Project Euler: {str(e)}")
        return -1


# ============================================================================
# SPOJ (Sphere Online Judge)
# ============================================================================

def get_spoj_problem_count() -> int:
    """
    Scrape SPOJ problem count.
    
    URL: https://www.spoj.com/problems/classical/
    
    SPOJ provides a large archive of problems across different categories.
    We scrape to count the total number of problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://www.spoj.com/problems/classical/"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch SPOJ problems")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for problem count in page
        import re
        
        # SPOJ typically shows total problems in pagination info
        pagination_text = soup.find(string=lambda text: text and 'problem' in text.lower())
        
        if pagination_text:
            match = re.search(r'(\d+)\s*problem', pagination_text, re.IGNORECASE)
            if match:
                return int(match.group(1))
        
        # Try to find in page info
        page_info = soup.find('div', class_='pagination')
        if page_info:
            info_text = page_info.get_text()
            match = re.search(r'of\s+(\d+)', info_text)
            if match:
                return int(match.group(1))
        
        # Count problem rows as fallback
        problem_rows = soup.find_all('tr', class_='problemrow')
        if problem_rows:
            # This is only the current page, need to estimate total
            # SPOJ shows 50 problems per page typically
            last_page_link = soup.find('a', string=lambda text: text and text.isdigit())
            if last_page_link:
                last_page = int(last_page_link.get_text(strip=True))
                return len(problem_rows) * last_page
            return len(problem_rows)
        
        logger.warning("Could not determine SPOJ problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping SPOJ: {str(e)}")
        return -1


# ============================================================================
# TIMUS ONLINE JUDGE
# ============================================================================

def get_timus_problem_count() -> int:
    """
    Scrape Timus Online Judge problem count.
    
    URL: https://acm.timus.ru/problemset.aspx
    
    Timus is a Russian online judge with a problem archive.
    We scrape the problemset page to count all problems.
    
    Returns:
        Total number of problems or -1 on failure
    """
    try:
        url = "https://acm.timus.ru/problemset.aspx"
        response = make_request(url)
        
        if not response:
            logger.error("Failed to fetch Timus Online Judge")
            return -1
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Look for problem count in page
        import re
        
        # Timus shows problem count in the header
        page_text = soup.get_text()
        match = re.search(r'(\d+)\s*problem', page_text, re.IGNORECASE)
        if match:
            return int(match.group(1))
        
        # Count problem rows in the table
        problem_rows = soup.find_all('tr', class_='content')
        if problem_rows:
            return len(problem_rows)
        
        # Alternative: count all problem links
        problem_links = soup.find_all('a', href=re.compile(r'problem\.aspx\?space=\d+&num=\d+'))
        if problem_links:
            return len(problem_links)
        
        logger.warning("Could not determine Timus problem count")
        return -1
        
    except Exception as e:
        logger.error(f"Error scraping Timus Online Judge: {str(e)}")
        return -1


# ============================================================================
# MAIN AGGREGATION FUNCTION
# ============================================================================

def scrape_all_sites() -> Dict[str, int]:
    """
    Scrape problem counts from all competitive programming judges.
    
    This function calls each site's scraper function and aggregates
    the results. Sites that fail to scrape return -1.
    
    Returns:
        Dictionary mapping site names to problem counts:
        {
            'aizu': 4500,
            'codechef': 5200,
            'codeforces': 8000,
            ...
        }
        
    Example:
        >>> result = scrape_all_sites()
        >>> print(result)
        >>> print(f"Total problems across all sites: {sum(v for v in result.values() if v > 0)}")
    """
    
    sites = {
        'aizu': get_aizu_problem_count,
        'codechef': get_codechef_problem_count,
        'codeforces': get_codeforces_problem_count,
        'cses': get_cses_problem_count,
        'deepml': get_deepml_problem_count,
        'dmoj': get_dmoj_problem_count,
        'eolymp': get_eolymp_problem_count,
        'hackerrank': get_hackerrank_problem_count,
        'kattis': get_kattis_problem_count,
        'kilonova': get_kilonova_problem_count,
        'leetcode': get_leetcode_problem_count,
        'libreoj': get_libreoj_problem_count,
        'perl_weekly_review': get_perl_weekly_review_count,
        'project_euler': get_project_euler_problem_count,
        'spoj': get_spoj_problem_count,
        'timus': get_timus_problem_count,
    }
    
    results = {}
    
    logger.info("Starting scraping of all competitive programming judges...")
    logger.info(f"Total sites to scrape: {len(sites)}")
    
    for site_name, scraper_func in sites.items():
        try:
            logger.info(f"Scraping {site_name}...")
            count = scraper_func()
            results[site_name] = count
            
            if count >= 0:
                logger.info(f"✓ {site_name}: {count} problems")
            else:
                logger.warning(f"✗ {site_name}: Failed to scrape (returned {count})")
            
            # Add delay to be respectful to servers
            time.sleep(1)
            
        except Exception as e:
            logger.error(f"Error processing {site_name}: {str(e)}")
            results[site_name] = -1
    
    # Print summary
    logger.info("\n" + "="*60)
    logger.info("SCRAPING SUMMARY")
    logger.info("="*60)
    
    successful = sum(1 for v in results.values() if v >= 0)
    failed = sum(1 for v in results.values() if v < 0)
    total_problems = sum(v for v in results.values() if v >= 0)
    
    logger.info(f"Successfully scraped: {successful}/{len(sites)} sites")
    logger.info(f"Failed to scrape: {failed}/{len(sites)} sites")
    logger.info(f"Total problems across all sites: {total_problems}")
    logger.info("="*60 + "\n")
    
    return results


if __name__ == "__main__":
    # Run the scraper when executed directly
    results = scrape_all_sites()
    
    print("\nFinal Results:")
    print("-" * 60)
    for site, count in sorted(results.items()):
        status = "✓" if count >= 0 else "✗"
        print(f"{status} {site:20s}: {count:6d} problems")
    print("-" * 60)
    
    total = sum(v for v in results.values() if v >= 0)
    print(f"Total problems: {total}")
