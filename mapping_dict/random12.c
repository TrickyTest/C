     #define _GNU_SOURCE     /* Expose declaration of tdestroy() */
       #include <search.h>
       #include <stdlib.h>
       #include <stdio.h>
       #include <time.h>

#define myp(aa,bb) printf("%s (%d)\n",aa,bb)

       static void *root = NULL;

       static void *
       xmalloc(unsigned n)
       {
           void *p;
           p = malloc(n);
           if (p)
               return p;
           fprintf(stderr, "insufficient memory\n");
           exit(EXIT_FAILURE);
       }

       static int
       compare(const void *pa, const void *pb)
       {
           if (*(int *) pa < *(int *) pb)
               return -1;
           if (*(int *) pa > *(int *) pb)
               return 1;
           return 0;
       }

       static void
       action(const void *nodep, const VISIT which, const int depth)
       {
           int *datap = *(int **) nodep;

           switch (which) {

           case preorder:
		myp("preorder",*datap);
               break;
           case postorder:
		myp("postorder",*datap);
//               datap = *(int **) nodep;
               printf("%6d\n", *datap);
               break;
           case endorder:
		myp("endorder",*datap);
               break;
           case leaf:
		myp("leaf",*datap);
//               datap = *(int **) nodep;
               printf("%6d\n", *datap);
               break;
           }
       }

       int
       main(void)
       {
           int i, *ptr;
           void *val;

           srand(time(NULL));
           for (i = 0; i < 12; i++) {
               ptr = xmalloc(sizeof(int));
               *ptr = rand() & 0xff;
               val = tsearch((void *) ptr, &root, compare);
               if (val == NULL)
                   exit(EXIT_FAILURE);
               else if ((*(int **) val) != ptr)
                   free(ptr);
           }
           twalk(root, action);
//           tdestroy(root, free);
           exit(EXIT_SUCCESS);
       }
