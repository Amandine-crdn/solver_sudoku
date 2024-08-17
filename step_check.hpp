#ifndef STEP_CHECK_HPP

    #define STEP_CHECK_HPP

    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <string>
    #include <cstdint> 
    #include <set>

    using namespace std;
    using Vector = vector<int>;
    using Iterator = Vector::iterator;


    class Grid {

        public:
            vector<Vector> grid;
            vector<Vector>::iterator itb_row;
            vector<Vector>::iterator ite_row;

            //getter
            vector<Vector> &get_grid() { return this->grid; }
            

            //setter
            void set_grid(int row, int i, char ascii) { 
                this->grid[row][i] = ascii - '0';
            }

            vector<Vector>::iterator get_begin() { return this->grid.begin(); }
            vector<Vector>::iterator get_end() { return this->grid.end(); }
            

        //constructeur par defaut
        Grid() :
            grid(vector<Vector>(9, Vector(9, 0))),
            itb_row(this->grid.begin()),
            ite_row(this->grid.end())
        {}

    };

    extern Grid t_grid; 

    int check_all_columns();
    int check_all_rows();


#endif

