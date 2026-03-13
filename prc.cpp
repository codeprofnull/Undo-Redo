#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//-------------Command------------------//
class Command{
    public:
    string action;
    int pos;
    char chr;

    Command(string a,int p,char c){
        action = a;
        pos = p;
        chr = c;
    }
};
//--------------Action Functions------------//
void Insert(vector<char> &doc, stack<Command> &undoStack, stack<Command> &redoStack, int p, char c){
    Command cmd = Command("Insert",p,c);
    doc.insert(doc.begin()+p,c);
    undoStack.push(cmd);
    while(!redoStack.empty()){redoStack.pop();};
}
void Backspace(vector<char> &doc, stack<Command> &undoStack, stack<Command> &redoStack, int p){
    char temp = doc.at(p);
    Command cmd = Command("Backspace",p,temp);
    doc.erase(doc.begin()+p);
    undoStack.push(cmd);
    while(!redoStack.empty()){redoStack.pop();};
}
void Undo(vector<char> &doc, stack<Command> &undoStack, stack<Command> &redoStack){
    if(undoStack.empty())return;
    else{
        Command top = undoStack.top() ;
        if(top.action == "Insert"){
            doc.erase(doc.begin()+top.pos);
        }
        else if (top.action == "Backspace"){
            doc.insert(doc.begin()+top.pos,top.chr);
        };
        undoStack.pop();
        redoStack.push(top);
    };
}
void Redo(vector<char> &doc, stack<Command> &undoStack, stack<Command> &redoStack){
    if(redoStack.empty())return;
    else{
        Command top = redoStack.top() ;
        if(top.action == "Insert"){
            doc.insert(doc.begin()+top.pos,top.chr);   
        }
        else if (top.action == "Backspace"){
            doc.erase(doc.begin()+top.pos);
        };
        redoStack.pop();
        undoStack.push(top);
    };
}
//-------------Helper Functions--------------//
void docview(vector<char> &doc){
    for(int i =0;i<doc.size();i++){
        cout << doc.at(i);
    }
    cout<< endl;
}

//---------template object for creating doc, work in prog----------//
/*class textdoc{
    public:
    vector<char> doc;
    stack<Command> undoStack;
    stack<Command> redoStack;

    textdoc(vector<char> docu, stack<Command> undoS, stack<Command> redoS){
        docu = doc;
        undoS = undoStack;
        redoS = redoStack;
    }
};*/

int main(){
        vector<char> doc;
        stack<Command> undoStack;
        stack<Command> redoStack;

        Insert(doc,undoStack,redoStack,0,'h');
        docview(doc);
        Insert(doc,undoStack,redoStack,1,'e');
        docview(doc);
        Insert(doc,undoStack,redoStack,2,'l');
        docview(doc);
        Insert(doc,undoStack,redoStack,3,'l');
        docview(doc);
        Insert(doc,undoStack,redoStack,4,'o');
        docview(doc);
        Undo(doc,undoStack,redoStack);
        docview(doc);
        Undo(doc,undoStack,redoStack);
        docview(doc);
        Redo(doc,undoStack,redoStack);
        docview(doc);

    
}