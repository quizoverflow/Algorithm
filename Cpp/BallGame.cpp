#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

#include <windows.h>

class Ball{

    public:
        double y, x;
        int x_dir; // right = 1, left -1
        int y_dir; // down =1 , up = -1
        double x_speed; // speed (m) / s
        double y_speed;
        double lastCollisionTime ;
        Ball(int Y, int X, int d, int s){
            x = X; x_dir = d; x_speed = s;
            y = Y; y_dir = 1; y_speed = 0;
            lastCollisionTime = 0;
        }
};

class Ground{
    private:
        int n,m;
        double tic;
        int frame;
        double gravity;
        vector<vector<char>> board;
        vector<Ball> balls;
    public:
        Ground(int N, int M){
            n = N; m = M;
            for(int i = 0; i< n; ++i){
                vector<char> tmp;
                for(int j = 0; j < m; ++j){
                    tmp.push_back(' ');
                }
                board.push_back(tmp);
            }
            gravity = 9.8;
            for(int i = 0; i < (n/2); ++i) cout << endl;
            cout<<"==================tic test ================="<<endl;
            for(int i = 0; i < (n/2); ++i) cout << endl;
            Sleep(1000);
            
            clock_t start, finish;
            start = clock();
            print();
            finish = clock();
            tic = double(finish - start) / CLOCKS_PER_SEC;
            frame = round(1.0 / tic);
        }
        void addBall(Ball b){
            balls.push_back(b);
        }

        void update(){
            Ball *ball;
            for(int i = 0; i < balls.size(); ++i){
                ball = &balls[i];
                board[(int)round(ball->y)][(int)round(ball->x)] = 'O';
            }
        }

        void print(){
            system("cls");
            for(int i = 0; i< n; ++i){
                for(int j = 0; j < m; ++j){
                    cout<<board[i][j];
                }
                cout<<"\n";
            }
            Sleep(20);
            cout<<endl;
        }

        void moveBall(double t){
            Ball *ball;
            for(int i = 0; i < balls.size(); ++i){
                ball = &balls[i];
                board[(int)round(ball->y)][(int)round(ball->x)] = ' ';
                // Axis X movement
                ball -> x += (ball -> x_dir) * (ball -> x_speed) * t;
                if(round(ball -> x) >= m && ball -> x_dir == 1){
                    ball -> x_dir = -1;
                    ball -> x = 2 * m - ball -> x;
                }
                else if (ball -> x <= 0 && ball -> x_dir == -1){
                    ball -> x_dir = 1;
                    ball -> x = -1 * ball -> x;
                }

                // Axis Y movement
                double T = t - ball ->lastCollisionTime;
                ball -> y = (ball -> y_speed * T) + 0.5 * gravity * T * T;
                if(round(ball -> y) >= n){
                    //ball -> y_dir = -1;
                    ball -> y = 2 * n - ball ->y;
                    ball ->lastCollisionTime = t;
                    ball -> y_speed = -1 * gravity * T;
                }
            }
        }

        void run(){
            clock_t start, time;
            double curr;
            start = clock();
            while(true){
                time = clock();
                curr = double(time - start) / CLOCKS_PER_SEC;
                moveBall(curr);
                update();
                print();

                if(curr >= 100.0) break;
            }
        }
};

int main(){
    FASTIO
    
    cout <<" input n , m values"<<endl;
    int n,m;
    cin >> n >> m;
    Ground ground(n,m);

    Ball b1(10,2,1,1);
    ground.addBall(b1);

    ground.run();

    return 0;
}