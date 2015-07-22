#include<iostream>
using namespace std;
struct node{
	int n;
	node *left, *right;}*root;

void inorder( node *t)
{
	if (!t) return;
	inorder(t->left);
	cout<<t->n<<",";
	inorder(t->right);
}
void nodeadd( int n)
{
	if(root==NULL)
	{
		root=new(node);
		root->n=n;
		root->left=root->right=NULL;
		return;
	}
	node *p=root;
	node *q=p;
	int l=0;
	while(p)
	{	
		q=p;
		if(p->n>=n) {p=p->left;l=0;}
		else {p=p->right; l=1;}
	}
	if(l)
	{
		q->right=new(node);
		node *r=q->right;
		r->n=n;
		r->left=r->right=NULL;
	}
	else
	{
		q->left=new(node);
		node *r1= q->left;
		r1->n=n;
		r1->left=r1->right=NULL;
	}
}	

main()
{
	int n;
	cout<<"\n how many nodes?\t";
	cin>>n;
	root=NULL;
	int num;
	while(n--)
	{	cin>>num;
		nodeadd(num);
	}		
	inorder(root);
}	
