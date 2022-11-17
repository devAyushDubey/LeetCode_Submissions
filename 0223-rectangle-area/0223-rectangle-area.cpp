class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int   bx2, int by2) {
    int area1 = (ax2-ax1)*(ay2-ay1) ,area2=(bx2-bx1)*(by2-by1);
	
	// length and breadth of the rectangle of overlapping 
    int xc = min(ax2,bx2)-max(ax1,bx1), yc=min(ay2,by2)-max(ay1,by1);  
  
    return (xc>0 && yc>0)?area1 + area2 -xc*yc :area1+area2;
        
    }
};
