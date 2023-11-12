#include "scr/Array.h"

using namespace std;

using dbl_point = pair<double, double>;
using int_point = pair<int, int>;

int main(){
    
    my_Array<shared_ptr<Figure<double>>> arr;
    cout << "To interact with programm, type number of the desired option:\n1) add to Array\n2) remove by index\n3) print array\n4) print geometric center and area of all figures\n5) quit\n";
    
    size_t option = 0;
    do{
        option = 0;
        cin >> option;
        if(option == 1){
            size_t fig_type = 0;
            cout << "Select figure to add:\n1) Triangle\n2) Square\n3) Rectangle\n";
            cin >> fig_type;
            
            try{
                if(fig_type == 1){
                    shared_ptr<Triangle<double>> tr = make_shared<Triangle<double>>();
                    *tr >> cin;
                    arr.push_back(tr);
                }
                if(fig_type == 2){
                    shared_ptr<Square<double>> sq = make_shared<Square<double>>();
                    *sq >> cin;
                    arr.push_back(sq);
                }
                if(fig_type == 3){
                    shared_ptr<Rectangle<double>> rect = make_shared<Rectangle<double>>();
                    *rect >> cin;
                    arr.push_back(rect);
                }
            }catch(exception &ex){
                cerr << "Exception in adding new figure: " << ex.what() << endl; 
            }
            
        }
        if(option == 2){
            size_t ind = 0;
            cout << "Type index (start from zero): ";
            cin >> ind;
            try{
                arr.pop_by_ind(ind);
            }catch(exception &ex){
                cerr << "Exception in removing by " << ind << ": " << ex.what() << endl;
            }
        }
        if(option == 3){
            try{
                for(size_t i = 0; i < arr._size; ++i){
                    cout << i+1 << ") "; (*(arr.get_by_ind(i)))<< cout << endl;
                }
            }catch(exception &ex){
                cerr << "Exception in printing: " << ex.what() << endl;
            }
        }
        if(option == 4){
            long double sum_area = 0;
            try{
                for(size_t i = 0; i < arr._size; ++i){
                    auto elem = (arr.get_by_ind(i));
                    dbl_point pt = dbl_point(elem->geom_cen());
                    cout << i+1 << ") Geometrical center of figure is: " << "(" << pt.first << ", " << pt.second << ')' << "; ";
                    cout << "Area of figure is: " << *elem << endl;
                    sum_area += static_cast<double>(*elem);
                }
                cout << "Sum area of all figures in array is " << sum_area << endl;
            }catch(exception &ex){
                cerr << "Exception in calculating: " << ex.what() << endl;
            }
        }
        if(option == 5){
            break;
        }
    }while (option);
    return 0;
}
