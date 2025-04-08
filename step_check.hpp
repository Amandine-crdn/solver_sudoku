#ifndef STEP_CHECK_HPP

    #define STEP_CHECK_HPP

    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <string>
    #include <cstdint> 
    #include <set>

    using namespace std;

    class Grid {

        public:
            vector<vector<int>> grid;
            vector<vector<int>>::iterator itb_row;
            vector<vector<int>>::iterator ite_row;

            //getter
            vector<vector<int>> &get_grid() { return this->grid; }
            

            //setter
            void set_grid(int row, int col, char value) { 
                this->grid[row][col] = value - '0';
            }

            void setter(int row, int col, int value) { 
                this->grid[row][col] = value;
            }


            vector<vector<int>>::iterator get_begin() { return this->grid.begin(); }
            vector<vector<int>>::iterator get_end() { return this->grid.end(); }
            
            //constructeur par defaut
            Grid() :
                grid(vector<vector<int>>(9, vector<int>(9, 0))),
                itb_row(this->grid.begin()),
                ite_row(this->grid.end())
            {}

            void print_sudoku() {
                for (itb_row = grid.begin(); itb_row != grid.end(); itb_row++) {
                    vector<int>::iterator vb = itb_row->begin();
                    vector<int>::iterator ve = itb_row->end();
                    for (vb; vb != ve; vb++) {
                        cout << *vb << " ";
                    }
                    cout << endl;
                }
            }

    };

    extern Grid t_grid; 
    
    int check_up();
    int solve_sudoku();

#endif

