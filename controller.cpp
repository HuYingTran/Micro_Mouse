#include "micro_mouse.h"

cell_t intlocal(0,0);
mouse m(intlocal);

int thuat_toan() {
    if(m.get_local()>m.get_front()) return tien;
    if(m.get_local()>m.get_right()) return re_phai;
    if(m.get_local()>m.get_left()) return re_trai;
    if(m.get_local()>m.get_back()) return quay_dau;
    return -1;
}

void hanh_dong() {
    switch (thuat_toan())
    {
    case tien:
        std::cout << "tien" << std::endl;
        m.tien(m.huong_current);
        break;
    case re_phai:
        std::cout << "re_phai" << std::endl;
        m.re_phai();
        break;
    case re_trai:
        std::cout << "re_trai" << std::endl;
        m.re_trai();
        break;
    case quay_dau:
        std::cout << "quay_day" << std::endl;
        m.quay_dau();
        break;
    default:
        break;
    }
}

int main() {
    in_map_vc();
    // init_map_diem();
    // in_map_diem();
    // for(int i=0;i<20;i++) {
    //     hanh_dong();
    //     std::cout << m.get_local() <<"->";
    // }
    return 0;
}