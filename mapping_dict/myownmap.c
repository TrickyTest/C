#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define myownmap_test

typedef struct PureStructNode {
	//int id;
	char * key;
	void * obj;
} * MapNode;



int map_cmp(const void *l, const void *r)
{
     MapNode lm = (MapNode)l;
     MapNode lr = (MapNode)r;
     #ifdef myownmap_test
     printf("Comparing: %s <=> %s >>> %d",lm->key,lr->key,strcmp(lm->key,lr->key));
     #endif
    return strcmp(lm->key,lr->key); //lm->key - lr->key;
}



void map_def(void * map,char *key,void *obj){
	//static int id=0; id++;
	#ifdef myownmap_test
	printf("def: %s\n",key);
	if (map==NULL) printf("map = null\n"); else printf("map != null\n");
	#endif
	
	MapNode Node = malloc(sizeof(struct PureStructNode));
	//Node->id  = id;
	Node->key = key;
	Node->obj = obj;
	void*p=tsearch(Node,&map,map_cmp); 
	if (p==NULL) printf("NULLDEF!\n"); else printf("OKDEF! %s=%s\n",Node->key,(char*)Node->obj);
}

void * map_get(void *map,char *key){
	#ifdef myownmap_test
	printf("GET: %s\n",key);
	#endif

	MapNode Node = malloc(sizeof(struct PureStructNode));
	Node->key=key;
	void * ret = tfind(Node,&map,map_cmp);
	if (ret==NULL) return NULL;
	return (*(MapNode*)ret)->obj;
}

#define map_str(map,key)\
	(char*)map_get(map,key)




#ifdef myownmap_test
int main(void){
	void *map =0;// NULL;
	printf("%s!\n","Define");
	map_def(map,"Jeroen","Broks");
	map_def(map,"Andre","Van Duyn");
	map_def(map,"Wim","Kok");
	map_def(map,"Raymond","van Barneveld");
	printf("%s!\n","Get");
	printf("%s\n",map_str(map,"Jeroen"));
	printf("%s\n",map_str(map,"Raymond"));
	printf("%s\n",map_str(map,"Andre"));
	printf("%s\n",map_str(map,"Wim"));
}
#endif
