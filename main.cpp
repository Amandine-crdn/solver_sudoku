#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct s_grid {
    vector<vector<int>> grid = vector<vector<int>>(9, vector<int>(9, 0));
    vector<vector<int>>::iterator itb_row = grid.begin();
    vector<vector<int>>::iterator ite_row = grid.end();

} t_grid;

int valid_row() {
    for (t_grid.itb_row; t_grid.itb_row != t_grid.ite_row; t_grid.itb_row++) {
        vector<int>::iterator vb = t_grid.itb_row->begin();
        vector<int>::iterator ve = t_grid.itb_row->end();
        for (vb; vb != ve; vb++) {
            cout << *vb << " ";
        }
        cout << endl;
    }
    return 0;

}

int valid_column() {
    return 0;
    
}

int check_up() {
    if (valid_row() || valid_column() != 0)
        return -1;    
    return 0;
}

int read_grille(ifstream &fichier) {
    
    string str;
    int row = 0;
    while (getline(fichier, str)) {
        int len_row = str.length();
        if (len_row != 9) {
            cerr << "Error read: invalid size" << endl; 
            return -1;
        }
        for (int i = 0; i != len_row; i++) {
            if (str[i] < 48 || str[i] > 57) {
                cerr << "Error read: invalid number (" << str[i] << ")" << endl; 
                return -1;
            }
            t_grid.grid[row][i] = str[i] - '0';
        }
        row++;
    }

    for (t_grid.itb_row; t_grid.itb_row != t_grid.ite_row; t_grid.itb_row++) {
        vector<int>::iterator vb = t_grid.itb_row->begin();
        vector<int>::iterator ve = t_grid.itb_row->end();
        for (vb; vb != ve; vb++) {
            cout << *vb << " ";
        }
        cout << endl;
    }

    return 0;
}

int main(int argc, char **argv) {

    ifstream fichier("grille_facile.txt");
    
    if (!fichier.is_open()) {
        cerr << "Error: can't open file" << endl;
        return -1;
    }
    if ((read_grille(fichier) || check_up()) != 0) {
        return -1;
    }
  

    

    fichier.close();
    return 0;
}