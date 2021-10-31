//
// Created by LENOVO on 2021/10/31.
//

#ifndef L6_CODE_SIMS_H
#define L6_CODE_SIMS_H

#define line_max 1024
typedef struct Country{
    char name[4];
    unsigned int rank;
}Country;

struct Country get_winner(struct Country a,struct Country b, int k);
void country_init_l6(struct Country* count_arr);
int file_read(struct Country* count_arr);
void print_result(struct Country* res_arr);
#endif //L6_CODE_SIMS_H
