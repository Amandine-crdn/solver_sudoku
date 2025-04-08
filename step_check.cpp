#include "step_check.hpp"



int valid_row(vector<vector<int>>::iterator &vi, string err) {
    vector<int>::iterator itb = vi->begin();
    vector<int>::iterator ite = vi->end();
    int number = 0;

    set<int> unique_values;
    pair<set<int>::iterator,bool> ret;

    for (itb; itb != ite; itb++) {
        number = *itb;
        ret = unique_values.insert(number);
        if (number != 0 && ret.second == false)  {
            cerr << err << number << ")" << endl;
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

int valid_carre() {
    // Créer "9 lignes avec 9 carrés et envoyer à check_row"
    Grid temp;

    int carre = 0; // Compteur pour les carrés
    int update_col = 0;
    int update_row = 0; // Ligne de départ
    int col_temp = 0;

    while (carre < 9) { // Faire pour les 9 carrés
        // Création d'une ligne grâce à un carré
        col_temp = 0;
        for (int row = update_row; row < update_row + 3 ; row++) { // Parcourt 3 lignes
            for (int col = update_col; col < update_col + 3; col++) { // Parcourt 3 colonnes
                temp.setter(carre, col_temp, t_grid.get_grid()[row][col]); // Valeur
                col_temp++;
            }
        }

        carre++;
        update_col +=3;

        if (carre % 3 == 0) {
            update_row += 3;
            update_col = 0;
        }
        
    }

    vector<vector<int>>::iterator itb, ite;
    itb = temp.get_begin();
    ite = temp.get_end();

    for (int i = 0; itb != ite; itb++, i++) {
        if (valid_row(itb, "Error: duplicate number inside carre (") != 0) {

            return -1;
        }
    }
    return 0;
}


int check_up() {
    vector<vector<int>>::iterator itb, ite;
    itb = t_grid.get_begin();
    ite = t_grid.get_end();

    for (int i = 0; itb != ite; itb++, i++) {
        if (valid_column(i) != 0 || valid_row(itb, "Error: duplicate number inside row (") != 0) {
            return -1;
        }
    }
    int a = valid_carre();
    return 0;
}

