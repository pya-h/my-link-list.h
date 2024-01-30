#ifndef LINK_LIST_H
#define LINK_LIST_H
    #include <stdio.h>

    typedef long long Long;
    #define MAX_ERROR_MESSAGE_LENGTH 256
    #define ABS(x) x >= 0 ? x : x * -1
    #define DIFF(x, y) ABS(x - y)
    // struct that is the base of our link list
    // using void * data-type, we can use this link list for every type in our app.
    typedef char Option;
    typedef enum {
        IntegerItem = (Option) 1,
        FloatItem,
        StringItem,
        //...
        CustomType
    } ListItemType;

    typedef struct ListItem
    {
        void *data;
        ListItemType type;    
        struct ListItem *next, *prev;
    } ListItem;
    
    // we define an outer struct, that will actually contain a link list;
    // this way we enhance the performance of the link list operations,
    // by setting the first and last item of the list (instead of finding the last item every time), and some fields [length till now]
    typedef struct List
    {
        ListItem *first, *last;
        char error[MAX_ERROR_MESSAGE_LENGTH];
        Long length;
        // next two fields is like a caching mechanism; it remembers the last item index that is accessed
        // when getting another item of a list, if the target index is close to this lastAccessIndex, we use that to process list
        // useful when using a List_at in a for loop
        Long lastAccessedIndex;
        ListItem *lastAccessedItem;
    } List;

    void *List_reset(List *list);
    List *newList();
    ListItem *newListItem(void *data);
    void ListItem_dump(ListItem *);
    ListItem *List_add(List *list, void *data);
    void *List_at(List *list, Long index);
    short List_deleteByIndex(List *list, Long index);
    char * List_getError(List *list);
    // void **List_toArray(List *list, Long index);
    void List_failure(List *, char *);
    Long List_getIndex(List *, void *);

    short List_deleteByItemData(List *, void *);
    ListItem *List_unlinkItem(List *, void *);

#endif //LINK_LIST_H