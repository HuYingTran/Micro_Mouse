#include "iostream"
#include <iomanip>

#define MAP_SIZE 16

class cell_t {
    public:
        int x,y;
        cell_t(int x, int y);
        void update(int idx, int idy);
};

enum ban_do_vc {c_khong = 0, c_truoc = 1, c_phai = 2, c_trai = 4, c_2ben = 6, c_t_phai = 3, c_t_trai = 5, c_cut = 7};

enum huong_t {dong = 1, nam = 2, tay = 3, bac = 4};
enum hanh_dong {stop = 0, tien = 1, quay_dau = 2, re_phai = 3, re_trai = 4};
enum vat_can {truoc = 1, phai = 2, trai = 3};

class mouse {
    public:
        int huong_current;
        uint8_t s_sensor;
        cell_t local, front, back, right, left;
        mouse(cell_t local);
        void tien(int huong);
        void re_phai();
        void re_trai();
        void quay_dau();
        int get_local(), get_back(), get_right(), get_front(), get_left();
};

void init_map_diem();
void in_map_diem();
void in_map_vc();