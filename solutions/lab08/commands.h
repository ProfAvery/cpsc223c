#ifndef COMMANDS_H
#define COMMANDS_H

extern bool verbose;

extern struct node *first_instruction;
extern struct node *current_instruction;

extern uint8_t byte;

void do_step(void);
void do_continue(void);
void do_print(void);
void do_list(void);

#endif

