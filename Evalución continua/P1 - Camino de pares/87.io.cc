// ALVARO BERZOSA TORDESILLAS
// F08
#include "bintree_eda.h"
#include <iostream>
#include <algorithm> // max

using namespace std;


int longestOddPath(const bintree<int> &tree, int &m)
{
	// Start coding here.
	if(tree.empty()){
		m = 0;
		return 0;
	}
	else{
		int izq, der, maxIzq, maxDer;
		izq = longestOddPath(tree.left(), maxIzq);
		der = longestOddPath(tree.right(), maxDer);
		if(tree.root() % 2 == 0){
			m = max(izq + 1 + der, max(maxIzq, maxDer));
			return max(izq, der) + 1;
		}
		else{
			m = max(maxIzq, maxDer);
			return 0;
		}
	}
  return 0 ;
}

int main(int argc, char **args)
{
  int N,n;
  cin >> N;
  for(n=0;n<N;n++)
    {
		int max = 0;
      bintree<int> tree;
      tree = leerArbol(-1);
		longestOddPath(tree, max);
      cout << max << endl;
    }
  return 0;
}
