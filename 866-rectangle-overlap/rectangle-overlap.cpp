class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0];
        int x2=rec1[2];
        int y1=rec1[1];
        int y2=rec1[3];
        int p1=rec2[0];
        int p2=rec2[2];
        int q1=rec2[1];
        int q2=rec2[3];
        // int maxi1=max(x1,p1);
        // int mini1=min(x2,p2);
        // int maxi2=max(y1,q1);
        // int mini2=min(y2,q2);
        // int comX=abs(maxi1-mini1);
        // int comY=abs(maxi2-mini2);
        if( min(p2,x2)>max(p1,x1) && min(q2,y2)>max(q1,y1)  )   return true;
        return false;
    }
};