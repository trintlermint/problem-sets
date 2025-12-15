fun D(n: Long):Boolean{val s=n.toString();return s.length%2==0&&s.substring(0,s.length/2)==s.substring(s.length/2)}
fun R(n:Long):Boolean{val s=n.toString();return(1 until s.length).any{k->s.length%k==0&&s.substring(0,k).repeat(s.length/k)==s}}
fun main(){val d=generateSequence(::readLine).joinToString("").trim();var a=0L;var b=0L;for(r in d. split(",")){if(r.isBlank())continue;val(lo,hi)=r.split("-").map{it.toLong()};for(n in lo..hi){if(D(n))a+=n;if(R(n))b+=n}};println(a);println(b)}
