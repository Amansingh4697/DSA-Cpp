class Node{
    public:
   int key,val;
   Node* next;
   Node* prev;
   int cnt;
   Node(int _key ,int _val){
      key = _key;
      val = _val;
      cnt = 1;
      next = nullptr;
      prev = nullptr;
   }
};
class List{
    public:
    int size;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    List(){
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};
class LFUCache {
  map<int,Node*> keyNode;
  map<int,List*> freqList;
  int maxCapacity;
  int currCapacity;
  int minFreq;
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        currCapacity = 0;
        minFreq = 0;
    }
    void UpdateFrequencyList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0 ){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
         
       // If the next higher frequency list already exists
       if(freqList.find(node->cnt + 1) != 
          freqList.end()) {
              
           // Update pointer to already existing list
           nextHigherFreqList = freqList[node->cnt + 1];
       }
       node->cnt += 1;
       nextHigherFreqList->addFront(node);
       freqList[node->cnt] = nextHigherFreqList;
       keyNode[node->key] = node; 
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            UpdateFrequencyList(node);
            return node->val; 
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(maxCapacity == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            UpdateFrequencyList(node);
        }else{
            if(currCapacity == maxCapacity){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currCapacity--;
            }
            currCapacity++;
            minFreq = 1;
            List* listFreq = new List(); 
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
