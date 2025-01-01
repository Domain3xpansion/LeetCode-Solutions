#define min(a,b)(a<b?a:(b<a?b:a))

int maxArea(int* height, int heightSize) {
    int start = 0, end = heightSize - 1;
    int area = 0, max_area = 0, length, breadth, left_line, right_line;
    while(start<end){
        /*could have taken length directly w/o storing the values of height[start] and height[end]
        in 2 sep variables but we also have to move the pointer, that's why*/
        left_line = height[start];
        right_line = height[end];
        length = min(left_line, right_line);
        // breadth is the distance between the two vertical lines
        breadth = end - start;
        area = length * breadth;
        if(area>max_area)
            max_area = area;
        /*this is the crucial part of the program
        we are moving the pointer which points to the lesser of the two values because ultimately, the
        smaller line out of the 2 lines dictate how much water can be stored. So, by moving the smaller li   
        ne's pointer, we are increasing our chance of getting the max area.*/
        if(left_line<=right_line)
            start++;
        else
            end--;
    }
    return max_area;
}