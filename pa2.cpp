// NAME: Yeung Pak Shing
// ID: 20116568
// EMAIL: psyeungaa@stu.ust.hk
// LAB SECTION: LA2

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int MAX_NUM_BITS = 10;
const int MAX_NUM_CODES = 1024; // 2^MAX_NUM_BITS



/*
 * A simple method for generating k-bit simple binary codes
 *
 * Variables:
 *    - binary_code[][]: 2D char array to store the k-bit simple binary codes.
 *      At the end, the codes are stored in the first 2^k rows of the leftmost
 *      k columns.
 *    - k: #bits for each simple binary code
 *    - starting_column: the starting column index to store each binary code
 *
 * Method:
 *    - The codes are basically generated from RIGHT to LEFT.
 *    - k should be > 0. It is checked anyway for completeness.
 *    - To generate k-bit binary codes, first generate (k-1)-bit binary codes
 *      which are stored in a 2D char array starting at an appropriate column.
 *    - Then these (k-1)-bit gray codes are copied to the next 2^(k-1) rows,
 *      also starting at the appropriate column.
 *    - Fix the leading bit: prepend '0' for the first half of codes, and
 *      '1' for the reflected codes as required.
 */
//           	generate_simple_binary_code(binary_code, n, 0);
//    			int n;              // #bits of binary codes
/*
 * 1.	Consider (column) 0 bit, 0,1, for row 0-1
 * 2.	Copy it  to row 3-4
 * 3.	Consider (column) 1 bit, 0,1, 0 for row 0-1, 1 for row 2-3
 */
void generate_simple_binary_code(char binary_code[][MAX_NUM_BITS+1], int k, int starting_column)
{
    // Base case #1: In general, k should be > 0; but add here to be safe
    if (k <= 0)
        return;

    // General case when k >= 1
	int num_codes = static_cast<int>(pow(2.0, k-1) + 0.5);

    generate_simple_binary_code (binary_code, k-1, starting_column+1);		//Step 1

	for (int i = 0; i < 2*num_codes; i++)	//Step 2
	{
		if (k != 1) //Exclude the base case from copying
			for (int j = 1; j < k; j++)	//j=0 is empty
				binary_code[i+num_codes][starting_column+j] = binary_code[i][starting_column+j];

		binary_code[i][starting_column] = ((i < (num_codes)) ? '0' : '1');		//Step 3
	}
}



/*
 * A simple method for generating k-bit gray codes
 *
 * Variables:
 *    - gray_code[][]: 2D char array to store the k-bit gray codes. At the end,
 *      the codes will be stored in the first 2^k rows and the leftmost k columns.
 *    - k: #bits for each gray code
 *    - starting_column: the starting column index to store each gray code
 *
 * Method:
 *    - The codes are basically generated from RIGHT to LEFT.
 *    - k should be > 0. It is checked anyway for completeness.
 *    - To generate k-bit gray codes, first generate (k-1)-bit gray codes which
 *      are stored in a 2D char array starting at an appropriate column.
 *    - Then these (k-1)-bit gray codes are reflected and stored in the next
 *      2^(k-1) rows also starting at the appropriate column.
 *    - Fix the leading bit: prepend '0' for the first half of codes, and
 *      '1' for the reflected codes as required.
 */
void generate_gray_code(char gray_code[][MAX_NUM_BITS+1], int k, int starting_column)
{
	int num_codes = static_cast<int>(pow(2.0, k-1) + 0.5);

    if (k <= 0)
        return;

    generate_gray_code (gray_code, k-1, starting_column+1);

	if (k != 1) //Exclude the base case from copying
		for (int i = 0; i < num_codes; i++)
			for (int j = 1; j < k; j++)
				gray_code[i+num_codes][starting_column+j] = gray_code[num_codes-i-1][starting_column+j];
				//num_codes-i = num_codes for i=0 ==> num_codes - (num_codes - 1) = 1, so need i-1

	for (int i = 0; i < 2*num_codes; i++)
		gray_code[i][starting_column] = ((i < (num_codes)) ? '0' : '1');		//Step 3
}

    /*
     * STEP 3: Prepend '0' to the original (k-1)-bit gray codes
     *             and '1' to the reflected (k-1)-bit gray codes
     *
     * If k = 1, the following codes also serve as the base case #2
     */
    // ADD YOUR CODE HERE


/*
 * An more efficient method for generating k-bit simple binary codes without saving the
 * codes in a 2D array. The codes are printed while they are generated.
 *
 * Variables:
 *    - binary_code[]: 1D char array to store one k-bit simple binary code.
 *    - i: the i-th bit of a simple binary code; it starts from 0, 1, ..., k
 *    - k: #bits for each simple binary code
 *
 * Method:
 *    - The codes are basically generated from LEFT to RIGHT.
 *    - Set the leading bit of k-bit binary codes to '0' and then recursively
 *      generate the (k-1)-bit binary codes
 *    - Repeat by setting the leading bit of k-bit binary codes to '1' and then
 *      recursively generate the (k-1)-bit binary codes
 */
//generate_simple_binary_code_X(code, 0, n);
void generate_simple_binary_code_X(char binary_code[], int i, int k)
{
    if (i == k)         // Base case: print out the code
        cout << binary_code << endl;
    else                // General case: i starts from 0, 1, ..., k
    {
        // Generate the first 2^(k-1) codes with leading zero
        binary_code[i] = '0';
        generate_simple_binary_code_X(binary_code, i+1, k);

        // Generate the next 2^(k-1) codes with leading one
        binary_code[i] = '1';
        generate_simple_binary_code_X(binary_code, i+1, k);
    }
}



/*
 * An more efficient method for generating k-bit gray codes without saving the
 * codes in a 2D array. The codes are printed while they are generated.
 *
 * Variables:
 *    - gray_code[]: 1D char array to store one k-bit gray code.
 *    - i: the i-th bit of a gray code; it starts from 0, 1, ..., k
 *    - k: #bits for each gray code
 *
 * Method:
 *    - The codes are basically generated from LEFT to RIGHT.
 *    - Initialize the all elements of gray_code[] array to '0'. (done beforehand)
 *    - Recursively generate the (k-1)-bit gray codes.
 *    - Implement the reflection! (tricky part)
 *    - Recursively generate the reflected (k-1)-bit gray codes.
 */
void generate_gray_code_X(char gray_code[], int i, int k)
{
    if (i == k)         // Base case: print out the code
        cout << gray_code << endl;
    else                // General case: i starts from 0, 1, ..., k
    {
        // STEP 1: Generate the remaining bits after the i-th bit
        // ADD YOUR CODE HERE
    	generate_gray_code_X(gray_code, i+1, k);
        // STEP 2: Reflection!
        // ADD YOUR CODE HERE
    	if (gray_code[i] == '1')
    		gray_code[i] = '0';
    	else
    		gray_code[i] = '1';

        // STEP 3: Generate the remaining bits after the i-th bit of the reflected Gray codes
        // ADD YOUR CODE HERE
    	generate_gray_code_X(gray_code, i+1, k);
    }
}



// Print either gray codes or binary codes that are stored in a 2D array
void print_code(const char code[][MAX_NUM_BITS+1], int n, const char codename[])
{
	int num_codes = static_cast<int>(pow(2.0, n) + 0.5);
    cout << endl << "Generate " << n << "-bit " << codename <<": " << endl;

    for(int i = 0; i < num_codes; i++)
    cout << code[i] << endl;
}




/*
 * Get the user's choice.
 * The available choices are: b/g/B/G
 */
char get_menu_choice(void)
{
    char choice;

    cout << endl << "Menu:" << endl;
    cout << "b. Generate simple binary codes by storing them in a 2D array" << endl;
    cout << "g. Generate Gray codes by storing them in a 2D array" << endl;
    cout << "B. Generate simple binary codes efficiently WITHOUT storing them" << endl;
    cout << "G. Generate Gray codes efficiently WITHOUT storing them" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (!(choice == 'b' || choice == 'g' || choice == 'B' || choice == 'G'));

    return choice;
}



int main(void)
{
    char choice;        // Generation method to use
    int n;              // #bits of binary codes
    cout << "How many bits of binary codes to generate? ";
    cin >> n;

    char gray_code[MAX_NUM_CODES][MAX_NUM_BITS+1] = { };
    char binary_code[MAX_NUM_CODES][MAX_NUM_BITS+1] = { };
    char code[MAX_NUM_BITS+1];


    switch (choice = get_menu_choice())
    {
        case 'b':
            generate_simple_binary_code(binary_code, n, 0);
            print_code(binary_code, n, "simple binary codes");
            break;

        case 'g':
            generate_gray_code(gray_code, n, 0);
            print_code(gray_code, n, "Gray codes");
            break;

        case 'B':
            code[n]='\0'; // Terminate the code to be generated
            cout << endl << "Generate "
                 << n << "-bit simple binary codes without storing them: " << endl;
            generate_simple_binary_code_X(code, 0, n);
            break;

        case 'G':
            for (int i = 0; i < n; i ++) // Initialize the code to all '0's
                code[i]='0';
            code[n]='\0'; // Terminate the code to be generated

            cout << endl << "Generate "
                 << n << "-bit Gray codes without storing them: " << endl;
            generate_gray_code_X(code, 0, n);
            break;

        default:        // This shouldn't happen
            cerr << "Error: unsupported code generation!" << endl;
    }

    return 0;
}
