#include "micro_mouse.h"

int map_vc[MAP_SIZE][MAP_SIZE] = {
    {6,6,6,6,6,5,6,6,6,6,6,5,1,1,1,1},
    {1,1,1,1,1,6,1,1,1,1,1,6,1,1,1,1},
    {1,1,1,1,1,6,1,1,1,1,1,6,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,5,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

cell_t intlocal(0,0);
mouse m(intlocal);

int thuat_toan() {
    // printf("\nv_b %d=%d\n",m.back.x, m.back.y);
    if((m.get_local()>=m.get_front()) && !(m.s_sensor&(1<<0))) return tien;
    // printf("\nvr %d",m.get_right());
    // printf("\nvc %d\n",map_vc[m.local.x][m.local.y]);
    if((m.get_local()>=m.get_right()) && !(m.s_sensor&(1<<1))) {map_vc[m.local.x][m.local.y]=4; return re_phai;}
    if((m.get_local()>=m.get_left()) && !(m.s_sensor&(1<<2))) return re_trai;
    // if((m.get_local()>m.get_back()) && !(m.s_senor&(1<<1))) return quay_dau;
    return -1;
}

void hanh_dong() {
    switch (thuat_toan())
    {
    case tien:
        MM_LOGD( "tien");
        m.tien(m.huong_current);
        break;
    case re_phai:
        MM_LOGD( "re_phai");
        m.re_phai();
        break;
    case re_trai:
        MM_LOGD( "re_trai");
        m.re_trai();
        break;
    case quay_dau:
        MM_LOGD( "quay_day");
        m.quay_dau();
        break;
    default:
        break;
    }
}

int main() {
    in_map_vc(map_vc);
    init_map_diem();
    for(int i=0;i<30;i++) {
        in_map_diem(m.local.x, m.local.y);
        printf("\n");
        m.s_sensor = map_vc[m.local.x][m.local.y];
        hanh_dong();
        std::cout << m.get_local() << std::endl;
    }
    return 0;
}