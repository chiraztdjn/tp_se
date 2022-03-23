#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n=12,ref_str[12],frame[2],no=2,k,exist,df=0;

printf("\n ENTER REF VALUE :\n");
    for(i=1;i<=n;i++)
        scanf("%d",&ref_str[i]);

    for(i=0;i<no;i++)
                frame[i]= -1;  // initialize all page frame
                   j=0;         // initialize page frame pointer

  printf("\n ref string  \t page frames     df\n");
    for(i=1;i<=n;i++)
                {
                    printf("%d\t\t",ref_str[i]);
                    exist=0;          // Default value of existing ref  is 0
                    for(k=0;k<no;k++)
                    if(frame[k]==ref_str[i]) // input of  page  requested is compared with existing content of FRAME
                    {
                            exist=1;        // as page found available is turned 1
                            for(k=0;k<no;k++)
                                    printf("%d\t",frame[k]);   // Print Current state of FRAME
                            printf(" ");                        // Indication of no default page
                    }
                    if (exist==0)  // input   page  requested NOT existing in  FRAME
                            {
                                        frame[j]=ref_str[i];         // place page requested at j th location in FRAME
                                        j=(j+1)%no;            // Update J for next boucle
                                        df++;                // Increment Counter for Page Fault
                                        for(k=0;k<no;k++)
                                        printf("%d\t",frame[k]);  // Print Current state of FRAME
                                        printf("df");            // Indication of Page Fault
                            }
                            printf("\n");
                }
printf("Page Fault Is %d",df);
    return 0;
}
