/**@mainpage                                                            *
*   Titov Roman Group IU 8 -21                                          *
*   Laboratory  "Dynamic structures of data. Binary search tree"        *
*                                                                       */
/************************************************************************/
/// @brief                  HEADERS and namespace                      ///
#include<iostream>
using namespace std;
/************************************************************************/
/// @brief                       TEMPLATES                             /// 
/// Template node
/// {
template <class T,class I> class node
{
private:
	T x;      /// key
	I info;   /// information
	node* LL; /// left link
	node* RL; /// right link
public:

	node(){ x = 0; LL = 0; RL = 0;} /// Constructor of initilization

	~node()                          /// Destructor 
	{
		if (LL) LL -> ~node();
		if (RL) RL -> ~node();
		if (LL) { delete LL; LL = 0;}
		if (RL) { delete RL; RL = 0;}
	}                                ///
	
	void putx( T new_x, I new_info ){ /// Put information in field
		this -> x = new_x;
		this -> info = new_info;
	}                                 ///
	
	void null_leftlink(){ this -> LL = 0;}  /// Give zero value in left link
	
	void null_rightlink(){ this -> RL = 0;} /// Give zero value in right link

	/// @brief Add new node
	/// {
	void add( T new_x, I new_info )
	{
		if ( LL && ( new_x < x )){ LL -> add( new_x, new_info ); }

		if ( RL && ( new_x > x )){ RL -> add( new_x, new_info ); }

		if ( !LL &&( new_x < x )) /// If null left link
		{
			node* N = new node;
			N -> x = new_x;
			N -> info = new_info;
			N -> LL = 0;
			N -> RL = 0;
			LL = N;
		}

		if ( !RL && (new_x > x) ) /// If null right link
		{
			node* N = new node;
			N -> x = new_x;
			N -> info = new_info;
			N -> LL = 0;
			N -> RL = 0;
			RL = N;
		}
	}
	/// }

	/// @brief Print elements of tree
	/// {
	void print( int tab )
	{
		if( RL ){ RL -> print( tab + 1 ); }

		for ( int i = 1; i != tab; i++ )
			cout << "  "; cout << this -> x << "-"<< this -> info << endl;

		if( LL ){ LL -> print( tab + 1 ); }
	}
	/// }

	/// @brief Delete information
	/// {
	void del_all()
	{
		if (LL) { LL -> del_all(); }
		if (RL) { RL -> del_all(); }
		if (LL) { delete LL; LL =0 ;}
		if (RL) { delete RL; RL = 0;}
	}
	/// }

	/// @brief Write element 
	/// {
	I get(T getx)
	{
		if ( getx == x) return info;
		if ( LL && (getx < x )) return LL -> get( getx );
		if ( RL && (getx > x )) return RL -> get( getx );
	}
	/// }
};
/// }
/************************************************************************/
/// Template tree
/// {
template <class T, class I> class tree
{
private:
	node < T, I > *link;
public:

	tree(){ link = 0;} /// Constructor of initilization
	/// Destructor
	/// {
	~tree(){         
		if ( link )
			link -> ~node < T, I >();
		delete link;
		link = 0;
	}
	/// }

	/// @brief Add new item
	///
	void add(T new_x,I new_info)
	{
		if (link)
			link -> add( new_x, new_info );
		else
		{
			node<T,I> *N = new node<T,I>;
			N -> putx( new_x, new_info );
			N -> null_leftlink();
			N -> null_rightlink();
			link = N;
		}
	}
	/// }

	void print(){
		if( link )
			link->print(1);
		else cout << "No tree existing\n";
	}

	void del_all(){
		if( link )
			link -> del_all();
		delete link;
		link = 0;
	}
	void del(int x){
		if ( link )
			link->del(x);
	}
	I get(T x){
		if ( link )
			return link -> get(x);
		else cout << "No elements existing\n";
	}
};
/// }
/************************************************************************/
///                        MAIN FUNCTION                               ///
/// { 
int main()
{
	tree < int, char > *T = new tree < int, char >; /// Creating tree

    int c = 0;
    const int exit = 6;

    while ( c != exit )
    {
		/// Check  your answer
		cout << "Hello! This is a 'tree' example\n"
                 "There is a menu for you to choos:\n"
                 "  1-add;\n"
                 "  2-use destructor;\n"
                 "  3-print;\n"
                 "  4-delete all;\n"
                 "  5-get element;\n"
                 "  6-exit;\n"
                 "enter-> ";
		cin >> c;
		system("cls"); /// Clear screen

		/// Answer processing
		switch ( c ){
		case 1:{
			int key;
			char val;
			cout << "enter key: ";
			cin >> key;
			cout << "enter int value: ";
			cin >> val;
			T -> add( key, val);
			break;
		}
		case 2: T -> ~tree(); break;
		case 3: T -> print(); break;
		case 4: T -> del_all(); break;
		case 5:{
			cout << "what is key of element? ";
			int key = 0;
			cin >> key;
			cout << "there it is: " << T -> get(key) << endl;
			break;
		}
		default:
			if ( c != exit )
				cout << "wrong int value " << c << endl;
		}
	}
	delete T; // Delete tree, use destructor
}
/// }
/************************************************************************/