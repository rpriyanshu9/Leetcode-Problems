class BrowserHistory
{
public:
    struct Node
    {
        string val;
        Node *next;
        Node *prev;
    };

    Node *head = new Node();

    BrowserHistory(string homepage)
    {
        head->val = homepage;
        head->next = NULL;
        head->prev = NULL;
    }

    void visit(string url)
    {
        Node *newNode = new Node();
        newNode->val = url;
        newNode->prev = head;
        newNode->next = NULL;
        head->next = newNode;
        head = newNode;
    }

    string back(int steps)
    {
        while (head->prev != NULL && (steps--))
        {
            head = head->prev;
        }
        return head->val;
    }

    string forward(int steps)
    {
        while (head->next != NULL && (steps--))
        {
            head = head->next;
        }
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */