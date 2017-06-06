// grep "ab" ./1 |grep "ab" ./1 |awk '{print $1 "\t" $2}'
// grep "ab" ./1 |awk '{print $2}' | awk '{sum += $1}END{print sum}'
// 
// grep "ab" ./1 |grep "ab" ./1 |awk '{print $1 "\t" $2}' |sort -nrk 2

