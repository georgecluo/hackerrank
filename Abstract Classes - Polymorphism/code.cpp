
class LRUCache: public Cache {
    public:
    
    LRUCache(int cap) {cp = cap;}
    
    void set(int key, int val) {
        Node *set_node;
        
        if (mp.size() == 0 ) { //special case, if empty
            set_node = new Node(key, val); //create new head
            head = set_node;
            tail = set_node;
            mp[key] = set_node;
        }
        else {
            if (mp.find(key) != mp.end()) {
                set_node = mp[key];
                //update value
                set_node->value = val;
                
                //already in the cache, so update links to either side
                if (set_node->next != NULL) {
                    Node *old_next = set_node->next;
                    old_next->prev = set_node->prev;
                }
                if (set_node->prev != NULL) {
                    Node *old_prev = set_node->prev;
                    old_prev->next = set_node->next;
                }
            }
            else {
                //not previously in the cache...
                set_node = new Node(key, val); //create new head
                mp[key] = set_node;

                if (mp.size() > cp) {
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next; //memory management - get rid of the tail object
                    tail->next = NULL;
                }
            }
            //update links in current node
            set_node->next = head;
            head->prev = set_node;
            head = set_node;
            set_node->prev = NULL;
        }
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            return mp[key]->value;
        }
        return -1;
    }
    
};
