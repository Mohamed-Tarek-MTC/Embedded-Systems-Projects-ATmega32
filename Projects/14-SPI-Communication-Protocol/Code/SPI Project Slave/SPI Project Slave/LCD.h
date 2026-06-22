/*
 * IncFile1.h
 *
 * Created: 4/21/2026 11:29:08 PM
 *  Author: Cascoo
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

void LCD_init(void);
void LCD_send_char(char data);
void LCD_send_cmd(char cmd);
void PULSE();
void LCD_send_string(char* data);
void LCD_CLR_screen();
void LCD_RETURN_home();
void LCD_MOVE_cursor(char row, char column);
void move_cursor_right();
void move_cursor_left();
void shift_display_right();
void shift_display_left();

#endif /* INCFILE1_H_ */