#include "step_check.hpp"

int valid_row(vector<Vector>::iterator &vi) {
    Iterator itb = vi->begin();
    Iterator ite = vi->end();
    int number = 0;
    Iterator iterator_temp;

    for (itb; itb != ite; itb++) {
        number = *itb;
        iterator_temp = itb;
        if (number != 0) {
            for (iterator_temp; iterator_temp != ite; iterator_temp++) {
                if (iterator_temp != itb && *iterator_temp == number) {
                    cerr << "Error: duplicate number (" << number << ")" << endl;
                    return -1;
                }
            }
        }
    }
    return 0;
}

int check_all_rows() {
    //reinitialiser les iterator de grid
    
    t_grid.itb_row = t_grid.get_grid().begin();
    t_grid.ite_row = t_grid.get_grid().end();

    for (t_grid.itb_row; t_grid.itb_row != t_grid.ite_row; t_grid.itb_row++) {
        if (valid_row(t_grid.itb_row) != 0) {
            return -1;
        }
    }
    return 0;
}

int valid_column(int count, vector<Vector>::iterator &vector_iterator) {

    int number = 0;
    set<int> unique_values;
    vector<Vector>::iterator start = t_grid.get_begin();
    pair<set<int>::iterator,bool> ret;
    
    number = (*start)[count];
    for (int i = 0; i < 9; i++) {
        ret = unique_values.insert((*(start + i))[count]);
        if ((*(start + i))[count] != 0 && ret.second == false)  {
                cerr << "Error: duplicate number (" << number << ")" << endl;

        }
    }

    unique_values.clear();
    return 0;
    
}
int check_all_columns() {
    vector<Vector>::iterator itb, ite;
    itb = t_grid.get_begin();
    ite = t_grid.get_end();

    // for (int i = 0; i < 9; i++) {
    for (int i = 0; itb != ite; itb++, i++) {
        if (valid_column(i, itb) != 0) {
            return -1;
        }
    }
    return 0;
}

