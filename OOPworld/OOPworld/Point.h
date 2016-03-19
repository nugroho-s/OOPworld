//
// Header Point 
//

// fungsi utamanya untuk mengatur pergerakan objek turunan makhluk hidup

#ifndef _POINT_H
#define _POINT_H
class Point {
      public:
		// konstruktor
		Point ();
        Point (int _X, int _Y);
        
		// GETTER 
		int getX();
        int getY();

		// SETTER  
		void set(int _x, int _y);

		// memindahkan posisi (x, y) objek ke x+dx dan y+dy 
		void move (int dx, int dy);
		
		void printp();
		
      private:
		// koordinat objek di bidang
        int x;
        int y;
};
#endif
