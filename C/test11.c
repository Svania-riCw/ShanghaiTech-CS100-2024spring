#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#define WIDTH 40
#define HEIGHT 20
#define TANK1 'A'
#define TANK2 'B'
#define BULLET '*'
#define WALL '#'
#define EMPTY ' '

// 方向枚举
enum Direction { UP, DOWN, LEFT, RIGHT };

// 坦克结构体
typedef struct {
    int x, y;
    enum Direction dir;
    int health;
    char symbol;
} Tank;

// 子弹结构体
typedef struct {
    int x, y;
    enum Direction dir;
    bool active;
} Bullet;

// 游戏地图
char map[HEIGHT][WIDTH];

// 两个坦克
Tank tank1, tank2;

// 子弹数组(每个坦克最多5发子弹)
Bullet bullets1[5], bullets2[5];

// 初始化游戏
void initGame() {
    // 初始化地图
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                map[i][j] = WALL; // 边界墙
            } else {
                map[i][j] = EMPTY;
            }
        }
    }
    
    // 添加一些障碍物
    for (int i = 0; i < 10; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        map[y][x] = WALL;
    }
    
    // 初始化坦克1
    tank1.x = 2;
    tank1.y = HEIGHT / 2;
    tank1.dir = RIGHT;
    tank1.health = 3;
    tank1.symbol = TANK1;
    map[tank1.y][tank1.x] = tank1.symbol;
    
    // 初始化坦克2
    tank2.x = WIDTH - 3;
    tank2.y = HEIGHT / 2;
    tank2.dir = LEFT;
    tank2.health = 3;
    tank2.symbol = TANK2;
    map[tank2.y][tank2.x] = tank2.symbol;
    
    // 初始化子弹
    for (int i = 0; i < 5; i++) {
        bullets1[i].active = false;
        bullets2[i].active = false;
    }
}

// 绘制游戏画面
void drawGame() {
    system("cls"); // 清屏
    
    // 绘制地图
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    
    // 显示生命值
    printf("Tank A Health: %d\n", tank1.health);
    printf("Tank B Health: %d\n", tank2.health);
}

// 移动坦克
void moveTank(Tank *tank, enum Direction dir) {
    // 清除原位置
    map[tank->y][tank->x] = EMPTY;
    
    // 更新方向
    tank->dir = dir;
    
    // 计算新位置
    int newX = tank->x, newY = tank->y;
    switch (dir) {
        case UP:    newY--; break;
        case DOWN:  newY++; break;
        case LEFT:  newX--; break;
        case RIGHT: newX++; break;
    }
    
    // 检查是否可以移动
    if (map[newY][newX] == EMPTY) {
        tank->x = newX;
        tank->y = newY;
    }
    
    // 更新地图
    map[tank->y][tank->x] = tank->symbol;
}

// 发射子弹
void fireBullet(Tank *tank, Bullet bullets[]) {
    // 寻找一个未激活的子弹
    for (int i = 0; i < 5; i++) {
        if (!bullets[i].active) {
            bullets[i].x = tank->x;
            bullets[i].y = tank->y;
            bullets[i].dir = tank->dir;
            bullets[i].active = true;
            break;
        }
    }
}

// 更新子弹位置
void updateBullets() {
    // 更新坦克1的子弹
    for (int i = 0; i < 5; i++) {
        if (bullets1[i].active) {
            // 清除原位置
            if (map[bullets1[i].y][bullets1[i].x] == BULLET) {
                map[bullets1[i].y][bullets1[i].x] = EMPTY;
            }
            
            // 移动子弹
            switch (bullets1[i].dir) {
                case UP:    bullets1[i].y--; break;
                case DOWN:  bullets1[i].y++; break;
                case LEFT:  bullets1[i].x--; break;
                case RIGHT: bullets1[i].x++; break;
            }
            
            // 检查碰撞
            char target = map[bullets1[i].y][bullets1[i].x];
            if (target == WALL) {
                bullets1[i].active = false;
            } else if (target == TANK2) {
                tank2.health--;
                bullets1[i].active = false;
            } else if (target == EMPTY) {
                map[bullets1[i].y][bullets1[i].x] = BULLET;
            } else {
                bullets1[i].active = false;
            }
        }
    }
    
    // 更新坦克2的子弹(类似上面)
    for (int i = 0; i < 5; i++) {
        if (bullets2[i].active) {
            if (map[bullets2[i].y][bullets2[i].x] == BULLET) {
                map[bullets2[i].y][bullets2[i].x] = EMPTY;
            }
            
            switch (bullets2[i].dir) {
                case UP:    bullets2[i].y--; break;
                case DOWN:  bullets2[i].y++; break;
                case LEFT:  bullets2[i].x--; break;
                case RIGHT: bullets2[i].x++; break;
            }
            
            char target = map[bullets2[i].y][bullets2[i].x];
            if (target == WALL) {
                bullets2[i].active = false;
            } else if (target == TANK1) {
                tank1.health--;
                bullets2[i].active = false;
            } else if (target == EMPTY) {
                map[bullets2[i].y][bullets2[i].x] = BULLET;
            } else {
                bullets2[i].active = false;
            }
        }
    }
}

// 主游戏循环
void gameLoop() {
    while (true) {
        // 处理输入
        if (_kbhit()) {
            char ch = _getch();
            
            // 坦克1控制(WASD,空格发射)
            switch (ch) {
                case 'w': moveTank(&tank1, UP); break;
                case 's': moveTank(&tank1, DOWN); break;
                case 'a': moveTank(&tank1, LEFT); break;
                case 'd': moveTank(&tank1, RIGHT); break;
                case ' ': fireBullet(&tank1, bullets1); break;
            }
            
            // 坦克2控制(方向键,回车发射)
            switch (ch) {
                case 72: moveTank(&tank2, UP); break;    // 上箭头
                case 80: moveTank(&tank2, DOWN); break;  // 下箭头
                case 75: moveTank(&tank2, LEFT); break; // 左箭头
                case 77: moveTank(&tank2, RIGHT); break; // 右箭头
                case 13: fireBullet(&tank2, bullets2); break; // 回车
            }
        }
        
        // 更新子弹
        updateBullets();
        
        // 绘制游戏
        drawGame();
        
        // 检查游戏结束
        if (tank1.health <= 0) {
            printf("Tank B Wins!\n");
            break;
        }
        if (tank2.health <= 0) {
            printf("Tank A Wins!\n");
            break;
        }
        
        // 控制游戏速度
        Sleep(100);
    }
}

int main() {
    initGame();
    gameLoop();
    return 0;
}