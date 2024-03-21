#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//Weighted function
int weight(int x)
{
return int( x*x + (std::sqrt(x) + 4*x)*(1+std::sin(x)) ) % 23;
}

//Class
class dragon {
public:
int weightv;
int unwei;
static int comparison;

dragon (int unw){
unwei=unw;
weightv= weight(unwei);
}

//Member functions of the class
bool operator < (const dragon& b) const{
    comparison++;
    if (weightv==b.weightv){
        if(unwei<b.unwei){
            
            return true;
        }
    }
    else if (weightv<b.weightv){
        return true;
    }
    else{
        return false;
    }
}

};
int dragon::comparison =0;

//Sort functions of instances of class dragon
void sort1 (vector <dragon>& vec){
    bool swapped;
    for (int i = 0; i < vec.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j+1] < vec[j]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void vector_initialize (vector <dragon> a, int size){
    for (int i =0; i<size; i++){
        a.push_back(dragon(i));
    }
}

int main() {

for (int j=1; j<=10; j++){
vector <dragon> original;
vector <dragon> copy;
    for (int k =0; k<pow(2,j);k++)
    {original.push_back(dragon (k));}
    
    copy=original;
    sort1 (original);
    int save =dragon::comparison;
    dragon::comparison=0;
    std:: sort (copy.begin(), copy.end());

    cout << pow (2,j) << "     " << save << "    " << dragon::comparison << "    " << endl;
    dragon :: comparison =0;

    }
}


/*


    vector <dragon> original;
    vector <dragon> copy;

    for (int j=0; j<=10; j++){
    for (int k =0; k<pow(2,j);k++){
        original.push_back(dragon (k));
        }
    
    copy=original;
    sort1 (original);

    dragon::comparison=0;

    cout << pow(2,j) << setw(30) ;
    std:: sort (copy.begin(), copy.end());

    for (int z=0; z<pow(2,j);z++){
        cout << original[z].unwei;
    }

    cout<< setw(30);

    for (int h=0; h<pow(2,j);h++){
        cout<< copy [h].unwei;
    }

    cout << endl;

    }
}

*/



/*
// cout << left << setw(10) << "n" << left << setw(10) << "my sort" << left << setw(10) << "std sort" << endl;
  // cout << "===============================================\n";
 
  for (int i = 1; i <= 3; i++) {
    std::vector <dragon> vec1,vec2;
    for (int j=0; j < pow(2,i); j++) {
      vec1.push_back(dragon(j));
      vec2.push_back(dragon(j));
    }
  sort1(vec1);
  // cout << left << setw(10)<< pow(2,i) << left << setw(10) << hippo::count;
   
  // hippo::count = 0;
  std::sort(vec2.begin(), vec2.end());
    for (int j=0; j < pow(2,i); j++) {
      cout << vec1[j].unwei << " ";
      cout << vec2[j].unwei << endl;
    }
  // cout << left << setw(10)<< hippo::count << endl;
  }


int main() {




for (int j=1; j<=10; j++){
vector <dragon> original;
vector <dragon> copy;
    for (int k =0; k<pow(2,j);k++)
    {
        original.push_back(dragon (k));
    }
        
    // for (int z=0; z<pow(2,j);z++){
    //     cout << original[z].unwei << " ";
    // }
    
    copy=original;
    sort1 (original);
    int save =dragon::comparison;
    dragon::comparison=0;

    // for (int z=0; z<pow(2,j);z++){
    //     cout << original[z].unwei << " ";
    // }

    //cout << pow(2,j) << setw(30) ;
    std:: sort (copy.begin(), copy.end());

    // for (int h=0; h<pow(2,j);h++){
    //    // cout<< copy [h].unwei;
    // }

    cout << pow (2,j) << "     " << save << "    " << dragon::comparison << "    " << endl;
    dragon :: comparison =0;

    }



*/