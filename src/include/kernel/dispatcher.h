/**
 * @file
 * @brief Dispatcher
 */

#ifndef __DISPATCHER_H_
#define __DISPATCHER_H_

#include <kernel/pcb.h>
#include <common/stdlib.h>
#include <common/stdio.h>
#include <common/memory.h>
#include <common/queue.h>

//__attribute__((unused))static addr_t process_mem_space __attribute__((section(".bss")));

/**
 * Initializes the dispatcher.
 */
void dispatcher_init();
/**
 * Enqueues the running process into the ready queue, pops another process
 * from the queue and assigns it as the running process.
 */
void process_switch();
/**
 * Returns the adress for the PCB of the currently running process.
 *
 * @return Adress of the current process' PCB
 */
pcb_t *get_current_pcb();
/**
 * Initialize a pcb and enqueue the proces into the ready queue if it already
 * exists a running process, otherwise set it to running process.
 *
 * @param  process_function A pointer to a function (the process)
 *
 */
void spawn_process(void *process_function);

#endif
