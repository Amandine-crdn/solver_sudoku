#include "step_check.hpp"

Grid t_grid; 

int check_up() {
    if (check_all_rows() || check_all_columns() != 0)
        return -1;    
    return 0;
}

int read_grille(ifstream &fichier) {
    vector<Vector> &grid = t_grid.get_grid();

    string str;
    int row = 0;
    while (getline(fichier, str)) {
        int len_row = str.length();
        if (len_row != 9) {
            cerr << "Error read: invalid size" << endl; 
            return -1;
        }
        for (int i = 0; i != len_row; i++) {
            char ascii = str[i];
            if (ascii < 48 || ascii > 57) {
                cerr << "Error read: invalid number (" << ascii << ")" << endl; 
                return -1;
            }
            t_grid.set_grid(row, i, ascii);
        }
        row++;
    }

    cout << "START" << endl;
    t_grid.print_sudoku();
    
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

    solve_sudoku();

    cout << "\nEND GAME" << endl;
    t_grid.print_sudoku();

    

    fichier.close();
    return 0;
}