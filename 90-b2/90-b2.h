/* –≈16 2151299 À’º“√˙ */
#pragma once

#define ROW 8
#define COL 10

int menu();
void input_row_col(int* row, int* col, int* goal,int choice);
void create_begin_arr(int map[ROW][COL], int row, int col);
char change(char ch);
void cin1(int row, int col, char* map_x, char* map_y, int map[ROW][COL]);
void paint_now(int map[ROW][COL], char mark[ROW][COL], int row, int col);
void find_neighbor_for(int row, int col, int map[ROW][COL], char mark[ROW][COL]);
void find_neighbor_dg(int i,int j,int row, int col, int map[ROW][COL], char mark[ROW][COL]);
void find_same_num_and_mark(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y,int choice);
void paint_find_arr(char mark[ROW][COL], int row, int col);
void paint_colour_now(int map[ROW][COL], char mark[ROW][COL], int row, int col);
void wait_for_end_enter();
bool judge_neighbor(int map[ROW][COL], int i, int j, int row, int col);
void paint_arr(int row, int col, int map[ROW][COL], char mark[ROW][COL]);
void wait_for_enter_eliminate_zero(const char* const prompt = NULL);
void wait_for_enter_fill_new_value(const char* const prompt = NULL);
void paint_colour_fill_new_value(int map[ROW][COL], char mark[ROW][COL], int row, int col);
int find_max_num(int map[ROW][COL], int row, int col);
char wait_for_mix_enter(char map_x, char map_y);
void paint_colour_aftermix(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y);
void add_score(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int goal,int *all);
void paint_colour_after_eliminate_zero(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y);
void renew_mark(int row, int col, char mark[ROW][COL]);
void wait_for_mix_again(const char* const prompt = NULL);
void paint_background_5(int map[ROW][COL], int row, int col);
void paint_9_num(int num, int* X, int* Y, int highlight);
void paint_background_6(int map[ROW][COL], int row, int col);
void select_7(int map[ROW][COL], char mark[ROW][COL], int row, int col,int choice,int *goal);
void mark_highlight(int map[ROW][COL], char mark[ROW][COL], int row, int col);
void mark_return_highlight(int map[ROW][COL], char mark[ROW][COL], int row, int col);
void cls_paint_9_num(int X, int Y);
void wait_for_what(int ro,int step);
void cls_paint_9_num(int X, int Y);
void thelast_paint_colour_aftermix(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y, int choice, int *goal, int* all);
void wait_for_what(int row, int step);
void thelast_paint_colour_fall(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y, int choice);
void fall_move(int map[ROW][COL], char map_x, char map_y);
void thelast_paint_colour_fill(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y, int choice);
void thelast_add_score(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int goal, int* all);
void add_score2(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int* goal, int* all);
void find_neighbor_dg(int i, int j, int row, int col, int map[ROW][COL], char mark[ROW][COL]);
void wait_for_end_enter7();
int  create_random(int max);
void paint_background_66(int map[ROW][COL], int row, int col);