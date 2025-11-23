# Competitive Programming Judge Problem Count Scraper

This module aggregates the total number of problems available on various competitive programming and online judge websites.

## Installation

Install the required dependencies:

```bash
pip install -r requirements.txt
```

## Usage

### As a Python Module

```python
from scraper import scrape_all_sites

# Scrape all sites
result = scrape_all_sites()
print(result)

# Calculate total problems
total = sum(v for v in result.values() if v > 0)
print(f"Total problems across all sites: {total}")
```

### Individual Site Scrapers

```python
from scraper import (
    get_codeforces_problem_count,
    get_leetcode_problem_count,
    get_project_euler_problem_count
)

# Scrape a specific site
cf_count = get_codeforces_problem_count()
print(f"Codeforces: {cf_count} problems")
```

### As a Standalone Script

```bash
python3 scraper.py
```

This will scrape all sites and display a summary.

## Supported Judges

The scraper supports the following 16 competitive programming judges:

1. **Aizu Online Judge** - `https://onlinejudge.u-aizu.ac.jp/`
2. **CodeChef** - `https://www.codechef.com/`
3. **Codeforces** - `https://codeforces.com/`
4. **CSES Problem Set** - `https://cses.fi/`
5. **Deep-ML** - `https://www.deep-ml.com/`
6. **DMOJ** (Don Mills Online Judge) - `https://dmoj.ca/`
7. **EOlymp** - `https://www.eolymp.com/`
8. **HackerRank** - `https://www.hackerrank.com/`
9. **Kattis** - `https://open.kattis.com/`
10. **KiloNova** - `https://kilonova.ro/`
11. **LeetCode** - `https://leetcode.com/`
12. **LibreOJ** - `https://loj.ac/`
13. **Perl Weekly Review** - `https://theweeklychallenge.org/`
14. **Project Euler** - `https://projecteuler.net/`
15. **SPOJ** (Sphere Online Judge) - `https://www.spoj.com/`
16. **Timus Online Judge** - `https://acm.timus.ru/`

## Features

- **Error Handling**: Returns -1 if scraping fails for a site
- **Retry Logic**: Automatically retries failed requests (configurable)
- **Timeout Handling**: Each request has a 15-second timeout
- **User Agent Rotation**: Rotates through user agents to avoid blocking
- **Comprehensive Logging**: Detailed logs for debugging and monitoring
- **Graceful Degradation**: Continues scraping even if individual sites fail

## Configuration

You can modify the following constants in `scraper.py`:

```python
TIMEOUT = 15           # Request timeout in seconds
RETRY_ATTEMPTS = 2     # Number of retry attempts
RETRY_DELAY = 2        # Delay between retries in seconds
```

## Return Values

- Each scraper function returns an integer:
  - **Positive integer**: Number of problems available on the site
  - **-1**: Scraping failed (network error, site structure changed, etc.)

## Example Output

```
INFO:__main__:Starting scraping of all competitive programming judges...
INFO:__main__:Total sites to scrape: 16
INFO:__main__:Scraping aizu...
INFO:__main__:✓ aizu: 1450 problems
INFO:__main__:Scraping codechef...
INFO:__main__:✓ codechef: 5033 problems
...
============================================================
SCRAPING SUMMARY
============================================================
Successfully scraped: 14/16 sites
Failed to scrape: 2/16 sites
Total problems across all sites: 65720
============================================================
```

## Notes

- Some sites (like Deep-ML, KiloNova) may require authentication and return -1
- Sites with heavy JavaScript rendering may be difficult to scrape
- Problem counts are approximate and may change over time
- Be respectful of rate limits (the scraper includes 1-second delays between sites)

## License

This scraper is part of the problem-sets repository and follows the same license.
