#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode(){
        for (int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
};

TreeNode<int> *inputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of child " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int data;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter num of child of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " :";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ,";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

int numNodes(TreeNode<int> *root)
{
    if(root ==NULL){
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int> *root)
{
    if(root == NULL){
        return 0;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int sum = 0;
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        sum = sum + front->data;
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
    }
    return sum;
}

int sumNodesRecursive(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int rootData = root->data;
    int smallAns = 0;
    for (int i = 0; i < root->children.size(); i++){
        smallAns += sumNodesRecursive(root->children[i]);
    }
    return rootData + smallAns;
}

int maxDataNode(TreeNode<int> *root){
    if(root == NULL)
    {
        return 0;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int max = 0;
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front -> data > max){
            max = front->data;
        }
        for (int i = 0; i < front->children.size(); i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
}

TreeNode<int>* maxDataNodeRecursive(TreeNode <int> *root){
    if(root == NULL){
        return 0;
    }
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *temp = maxDataNodeRecursive(root->children[i]);
        if(temp -> data > maxNode -> data){
            maxNode = temp;
        }
        return maxNode;
    }
}

int getHeight(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    if(root -> children.size() == 0){
        return 1;
    }
    int height = 0;
    for (int i = 0; i < root->children.size(); i++){
        int childHeight = getHeight(root->children[i]);
        if(childHeight > height){
            height = childHeight;
        }
    }
    return height + 1;
}

void printAtLevelK(TreeNode<int> *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}

int countLeafNodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    if(root -> children.size() == 0){
        return 1;
    }
    int smallAns = 0;
    for (int i = 0; i < root->children.size(); i++){
        smallAns = countLeafNodes(root->children[i]);
    }
    return smallAns + 1;
}

void preOrder(TreeNode<int> *root){
    if(root == NULL){
        return;
    }

    cout << root->data << endl;

    for (int i = 0; i < root->children.size(); i++){
        preOrder(root->children[i]);
    }
}

 void postOrder(TreeNode<int> *root)
{
    if(root == NULL){
        return;
    }
    for (int i = 0; i < root->children.size(); i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root){
    for (int i = 0; i < root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

// Assignment questions 

bool containsX(TreeNode<int> *root, int x){
    if(root == NULL){
        return false;
    }
    if(root -> data == x){
        return true;
    }
    bool ans = false;
    for (int i = 0; i < root->children.size(); i++){
        ans = containsX(root->children[i], x);
        if(ans == true){
            return true;
        }
    }
    return ans;
}

int greaterThanX(TreeNode<int> *root, int x){
    if(root == NULL){
        return 0;
    }
    if(root -> data > x){
        return 1;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++){
        count += greaterThanX(root->children[i], x);
    }
    return count;
}

//1 3 2 3 4 2 5 6 0 0 0 0
int main()
{

    TreeNode<int> *root = inputLevelWise();
    cout << greaterThanX(root, 2);
    cout << endl;
    bool ans = containsX(root, 8);
    if(ans == true){
        cout << "True" << endl;
    }
    else{
        cout << "false";
    }

    /*   cout << sumNodesRecursive(root);
    cout << endl;
    cout << sumNodes(root); 
    */
    // printLevelWise(root);
    // cout << getHeight(root) << endl;
    // postOrder(root);
    deleteTree(root);
    // cout << countLeafNodes(root) << endl;

    // printAtLevelK(root, 2);

    // int num = numNodes(root);
    // cout << num << endl;
    // cout << sumNodes(root) << endl;
    // cout << maxDataNode(root) << endl;
    // cout << getHeight(root) << endl;

    /*  TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    delete root;
*/
}