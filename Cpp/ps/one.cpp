/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

char int_to_color[6] = {'w','y','r','o','g','b'};
enum color_to_int {U,D,F,B,L,R};

void doRotation(int *a, int *b, int *c, int *d, bool clockWise){
    int original[4][3];
    memcpy(original[0],a,12);
    memcpy(original[1],b,12);
    memcpy(original[2],c,12);
    memcpy(original[3],d,12);
    if(clockWise){
        //오른쪽으로 밀기
        memcpy(b,original[0],12);
        memcpy(c,original[1],12);
        memcpy(d,original[2],12);
        memcpy(a,original[3],12);
    }
    else{
        //왼쪽으로 밀기
        memcpy(a,original[1],12);
        memcpy(b,original[2],12);
        memcpy(c,original[3],12);
        memcpy(d,original[0],12);
    }
    
}

class Area{
    public:
        int area[3][3];
        Area(int areaColor){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j< 3; ++j) area[i][j] = areaColor;
            }
        }

        void getLine(bool is_row, int idx, int *ap);
        void setLine(bool is_row, int idx, int *ap);
        void changeThisArea(bool isClockWise);
};
void Area::getLine(bool is_row,int idx, int *ap){
    if(is_row){
        memcpy(ap, area[idx], 12);
    }
    else{
        for(int i = 0; i < 3; ++i){
            ap[i] = area[i][idx];
        }
    }
}
void Area::setLine(bool is_row,int idx, int *ap){
    if(is_row){
        memcpy(area[idx], ap, 12);
    }
    else{
        for(int i = 0; i < 3; ++i){
            area[idx][i] = ap[i];
        }
    }
}
void Area:: changeThisArea(bool isClockWise){
    
}

int main(void){
    FASTIO
    int test_case;
    cin >> test_case;
    while(test_case--){

        int rotate_count;
        cin >> rotate_count;
        
        //면 객체 6개 생성, 각각의 색으로 초기화
        Area u(0), d(1), f(2), b(3), l(4), r(5);

        /*
        1)명령 확인 : 돌릴 면 (target), 돌릴 방향 (is_clockWise)
        2)명령 수행 : 돌릴 면객체 멤버 변수 area업데이트, 영향 가는 면객체 멤버 변수 area 업데이트

        */
        string order;
        for(int i = 0; i < rotate_count; ++i){
            cin >> order;
            char target = order[0];
            bool is_clockWise = order[1] == '+' ? true : false;
            switch (target)
            {
            case 'U':
                int targetLines[4][3];
                u.getLine(true,2,targetLines[0]);
                u.getLine(false,0,targetLines[1]);
                u.getLine(true,0,targetLines[2]);
                u.getLine(false,2,targetLines[3]);
            
                break;

            case 'D':
                /* code */
                break;

            case 'R':
                /* code */
                break;

            case 'B':
                /* code */
                break;

            case 'L':
                /* code */
                break;

            case 'F':
                /* code */
                break;
            }
        }

    }

    
    



    return 0;
}