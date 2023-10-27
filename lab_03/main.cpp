#include "scr/Array.h"

int main(){
    
    Array *arr = new Array;
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
                    Triangle *tr = new Triangle;
                    cin >> *tr;
                    arr->push_back(tr);
                }
                if(fig_type == 2){
                    Square *sq = new Square;
                    cin >> *sq;
                    arr->push_back(sq);
                }
                if(fig_type == 3){
                    Rectangle *rt = new Rectangle;
                    cin >> *rt;
                    arr->push_back(rt);
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
                arr->pop_by_ind(ind);
            }catch(exception &ex){
                cerr << "Exception in removing by " << ind << ": " << ex.what() << endl;
            }
        }
        if(option == 3){
            for(size_t i = 0; i < arr->size(); ++i){
                cout << i+1 << ") " << arr->array()[i] << endl;
            }
        }
        if(option == 4){
            long double sum_area = 0;
            try{
                for(size_t i = 0; i < arr->size(); ++i){
                    Point pt = Point((arr->array()[i])->geometrical_centre());
                    cout << i+1 << ") Geometrical center of figure is: " << "(" << pt.x_pnt << ", " << pt.y_pnt << ')' << "; ";
                    cout << "Area of figure is: " << *(arr->array()[i]) << endl;
                    sum_area += static_cast<double>(*(arr->array()[i]));
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
