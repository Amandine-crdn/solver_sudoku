#include "step_check.hpp"

int valid_carre() {
    
}

int valid_row(vector<vector<int>>::iterator &vi) {
    vector<int>::iterator itb = vi->begin();
    vector<int>::iterator ite = vi->end();
    int number = 0;

    set<int> unique_values;
    pair<set<int>::iterator,bool> ret;

    for (itb; itb != ite; itb++) {
        number = *itb;
        ret = unique_values.insert(number);
        if (number != 0 && ret.second == false)  {
            cerr << "Error: duplicate number inside row (" << number << ")" << endl;
            return -1;

        }
    }
    unique_values.clear();
    return 0;
}

int valid_column(int count) {
    int number = 0;
    vector<vector<int>>::iterator start = t_grid.get_begin();
    set<int> unique_values;
    pair<set<int>::iterator,bool> ret;
    
    for (int i = 0; i < 9; i++) {
        number = (*(start + i))[count];
        ret = unique_values.insert(number);
        if (number != 0 && ret.second == false)  {
            cerr << "Error: duplicate number inside column (" << number << ")" << endl;
            return -1;

        }
    }

    unique_values.clear();
    return 0;   
}

int check_up() {
    vector<vector<int>>::iterator itb, ite;
    itb = t_grid.get_begin();
    ite = t_grid.get_end();

    for (int i = 0; itb != ite; itb++, i++) {
        if (valid_column(i) != 0 || valid_row(itb) != 0) {
            return -1;
        }
    }
    return 0;
}

