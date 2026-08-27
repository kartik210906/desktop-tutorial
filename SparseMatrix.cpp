#include <iostream>
using namespace std;

class sparse {
    int row, col, val;
public:
    sparse(int r = 0, int c = 0, int v = 0) {
        row=r;
        col=c;
        val=v;
    }

    void readMatrix(sparse a[]) {
        cout << "Enter the number of rows and columns of the matrix: " << endl;
        cin >> row >> col;
        int mat[row][col];
        int nz = 0;
        cout << "Enter the elements of the matrix: " << endl;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                cin >> mat[i][j];
                if (mat[i][j] != 0) a[++nz] = sparse(i, j, mat[i][j]);
            }
        a[0] = sparse(row, col, nz);

        cout << "The entered matrix is: " << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) cout << mat[i][j] << " ";
            cout << endl;
        }
        cout<<endl;
        cout<<"Triplet Respresentation Is: "<<endl;
        displaySparse(a);
    }
    
    void displaySparse(sparse a[]) {
        cout << "Row\tColumn\tValue" << endl;
        for (int i = 0; i <= a[0].val; i++)
        cout << a[i].row << "\t" << a[i].col << "\t" << a[i].val << endl;
        cout<<endl;
    }
    
    void transpose(sparse a[], sparse at[]) {
        at[0] = sparse(a[0].col, a[0].row, a[0].val);
        for (int i = 1; i <= a[0].val; i++)
            at[i] = sparse(a[i].col, a[i].row, a[i].val);

        for (int i = 1; i <= at[0].val; i++)
            for (int j = i + 1; j <= at[0].val; j++)
                if (at[i].row > at[j].row) swap(at[i], at[j]);
    }

    void fastTranspose(sparse a[], sparse at[]) {
        int rowTerms[100] = {0};
        int startingPos[100];

        int rows = a[0].row;
        int cols = a[0].col;
        int terms = a[0].val;

        // Step 1: Count elements in each column
        for (int i = 1; i <= terms; i++)
        {
            rowTerms[a[i].col]++;
        }
        // Step 2: Find starting position
        startingPos[0] = 1;
        for (int i = 1; i < cols; i++)
        {
            startingPos[i] =
                startingPos[i - 1] + rowTerms[i - 1];
        }

        // Header of transpose
        at[0].row = cols;
        at[0].col = rows;
        at[0].val = terms;

        // Step 3: Place elements
        for (int i = 1; i <= terms; i++)
        {
            int pos = startingPos[a[i].col]++;

            at[pos].row = a[i].col;
            at[pos].col = a[i].row;
            at[pos].val = a[i].val;
        }
        cout<<"Transpose Using Fast Transpose Algorithm"<<endl;
        displaySparse(at);
    }

    void transposeDisplay(sparse a[]) {
        sparse at[100];
        transpose(a, at);
        cout << "The transposed matrix is: " << endl;
        displaySparse(at);
    }

    void add(sparse a[], sparse b[]) {
        if (a[0].row != b[0].row || a[0].col != b[0].col) {
            cout << "Matrices cannot be added" << endl;
            return;
        }
        sparse c[100];
        c[0] = sparse(a[0].row, a[0].col, 0);
        int i = 1, j = 1, k = 1;
        while (i <= a[0].val && j <= b[0].val) {
            if (a[i].row == b[j].row && a[i].col == b[j].col) {
                c[k] = sparse(a[i].row, a[i].col, a[i].val + b[j].val);
                ++k;
                ++i;
                ++j;
            }
            else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)){
                c[k] = a[i];
                k++;
                i++;
            }
            else{
                c[k] = b[j];
                k++;
                j++;
            }
        }
        while (i <= a[0].val) c[k++] = a[i++];
        while (j <= b[0].val) c[k++] = b[j++];
        c[0].val = k - 1;
        cout << "The sum of the matrices is: " << endl;
        displaySparse(c);
    }

    void multiply(sparse a[], sparse b[]) {
        if (a[0].col != b[0].row) {
            cout << "Matrices cannot be multiplied" << endl;
            return;
        }
        sparse bT[100], c[100];
        transpose(b, bT);
        c[0] = sparse(a[0].row, b[0].col, 0);
        int t = 1;
        for (int i = 1; i <= a[0].val; i++) {
            for (int j = 1; j <= bT[0].val; j++) {
                int sum = 0;
                for (int p = 1; p <= a[0].val; p++)
                    for (int q = 1; q <= bT[0].val; q++)
                        if (a[p].row == a[i].row && bT[q].row == bT[j].row && a[p].col == bT[q].col)
                            sum += a[p].val * bT[q].val;
                if (sum != 0){
                    c[t] = sparse(a[i].row, bT[j].row, sum);
                    t++;
                }
            }
        }
        c[0].val = t-1;
        cout << "The product of the matrices is: " << endl;
        displaySparse(c);
    }
};

int main() {
    int choice;
    sparse s, a[100], b[100];

    do {
        cout << "1. Read sparse matrices And Convert to Triplets\n2. Add two sparse matrices\n3. Transpose a sparse matrix\n"
             << "4. Multiply two sparse matrices\n5. Fast Transpose \n0.Exit\nEnter your choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1:
                s.readMatrix(a);
                break;
            case 2:
                cout << "Enter the first matrix: " << endl; s.readMatrix(a);
                cout << "Enter the second matrix: " << endl; s.readMatrix(b);
                s.add(a, b);
                break;
            case 3:
                s.readMatrix(a);
                s.transposeDisplay(a);
                break;
            case 4:
                cout << "Enter first matrix: " << endl; s.readMatrix(a);
                cout << "Enter second matrix: " << endl; s.readMatrix(b);
                s.multiply(a, b);
                break;
            case 5:
                cout<<"Enter Your Matrix: "<<endl;
                s.readMatrix(a);
                s.fastTranspose(a,b);
                break;
                
            default:
                cout<<"Invalid Choice !"<<endl;
                break;
        }
    } while (choice != 0);
    return 0;
}