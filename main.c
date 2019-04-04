#include "pcb.h"
#include "asl.h"
#include "const.h"
#include "types.h"

int main(){

/*inizializzo le new area*/

/***************************** INIT CPU0 */
    ((state_t *)INT_NEWAREA)->pc_epc = ((state_t *)INT_NEWAREA)->reg_t9 = (memaddr)int_handler;
    ((state_t *)INT_NEWAREA)->reg_sp = RAMTOP;
    ((state_t *)INT_NEWAREA)->status = EXCEPTION_STATUS;

    ((state_t *)TLB_NEWAREA)->pc_epc = ((state_t *)TLB_NEWAREA)->reg_t9 = (memaddr)tlb_handler;
    ((state_t *)TLB_NEWAREA)->reg_sp = RAMTOP;
    ((state_t *)TLB_NEWAREA)->status = EXCEPTION_STATUS;

    ((state_t *)PGMTRAP_NEWAREA)->pc_epc = ((state_t *)PGMTRAP_NEWAREA)->reg_t9 = (memaddr)pgmtrap_handler;
    ((state_t *)PGMTRAP_NEWAREA)->reg_sp = RAMTOP;
    ((state_t *)PGMTRAP_NEWAREA)->status = EXCEPTION_STATUS;

    ((state_t *)SYSBK_NEWAREA)->pc_epc = ((state_t *)SYSBK_NEWAREA)->reg_t9 = (memaddr)sysbk_handler;
    ((state_t *)SYSBK_NEWAREA)->reg_sp = RAMTOP;
    ((state_t *)SYSBK_NEWAREA)->status = EXCEPTION_STATUS;


/* chiamo la funzione initPcbs()*/
initPcbs();

}