#include "micro_mouse.h"

MM_LEVEL MM_L = MM_INFO;

#define TAG_DEBUG MM_L

int map_diem[MAP_SIZE][MAP_SIZE] = {0};

void MM_LOGD(const char *string) {
    if(TAG_DEBUG == MM_BUG){
        std::cout << string << std::endl;
    }
}

void in_map_vc(int map_vc[MAP_SIZE][MAP_SIZE]){
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            switch (map_vc[i][j])
            {
            case c_khong:
                std::cout << " ";
                break;
            case c_truoc:
                std::cout << "|";
                break;
            case c_phai:
                std::cout << "``";
                break;
            case c_2ben:
                std::cout << "=";
                break;
            case c_t_phai:
                std::cout << "⅃";
                break;
            case c_t_trai:
                std::cout << "⅂";
                break;
            case c_cut:
                std::cout << "]";
            default:
                break;
            }

        }
        std::cout << std::endl;
    }
}

void in_map_diem(int x, int y)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if(i == x && j == y) {printf(".");}
            std::cout << std::setw(3) << map_diem[i][j];

        }
        std::cout << std::endl;
    }
}

void init_map_diem() {
    int cell = MAP_SIZE/2 -1; //=7
    for(int i = 0; i <=cell ; i++) {
        for(int j = 0; j <= cell; j++) {
            map_diem[cell-i][cell-j] = i+j;
            map_diem[cell-i][cell+j+1] = i+j;

            map_diem[cell+i+1][cell-j] = i+j;
            map_diem[cell+i+1][cell+j+1] = i+j;
        }
    }
}

cell_t::cell_t(int x, int y) {
    this->x = x;
    this->y = y;
}

void cell_t::update(int idx, int idy) {
    this->x += idx;
    this->y += idy;
}

mouse::mouse(cell_t local) : local(local), front(cell_t(0,1)), back(cell_t(0,-1)), right(cell_t(1,0)), left(cell_t(-1,0)) {
    this->huong_current = dong;
    this->s_sensor = 0b000;
}

void mouse::tien(int huong) {
    switch (huong)
    {
    case dong:
        this->local.update(0,1);
        this->front.update(0,1);
        this->back.update(0,1);
        this->left.update(0,1);
        this->right.update(0,1);
        break;
    case tay:
        this->local.update(0,-1);
        this->front.update(0,-1);
        this->back.update(0,-1);
        this->left.update(0,-1);
        this->right.update(0,-1);
        break;
    case bac:
        this->local.update(-1,0);
        this->front.update(-1,0);
        this->back.update(-1,0);
        this->left.update(-1,0);
        this->right.update(-1,0);
        break;
    case nam:
        this->local.update(1,0);
        this->front.update(1,0);
        this->back.update(1,0);
        this->left.update(1,0);
        this->right.update(1,0);
        break;
    default:
        break;
    }
}

void mouse::re_phai() {
    cell_t temp(this->front.x,this->front.y);
    this->front=this->right;
    this->right=this->back;
    this->back=this->left;
    this->left=temp;
    this->huong_current +=1;
    if(this->huong_current>4) this->huong_current=1;
}

void mouse::re_trai() {
    cell_t temp(this->front.x,this->front.y);
    this->local=this->left;
    this->left=this->back;
    this->back=this->right;
    this->right=temp;
    this->huong_current -= 1;
    if(this->huong_current<1) this->huong_current=4;
}

void mouse::quay_dau() {
    this->re_phai();
    this->re_phai();
}

int mouse::get_local() {return map_diem[this->local.x][this->local.y];}
int mouse::get_back() {return map_diem[this->back.x][this->back.y];}
int mouse::get_front() {return map_diem[this->front.x][this->front.y];}
int mouse::get_right() {return map_diem[this->right.x][this->right.y];}
int mouse::get_left() {return map_diem[this->left.x][this->left.y];}