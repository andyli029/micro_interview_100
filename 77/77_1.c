//如果head1==head2，那么显然相交，直接返回head1。
//否则，分别从head1,head2开始遍历两个链表获得其长度len1与len2，假设len1>=len2，
//那么指针p1由head1开始向后移动len1-len2步，指针p2=head2，
//下面p1、p2每次向后前进一步并比较p1p2是否相等，如果相等即返回该结点，
//否则说明两个链表没有交点。


