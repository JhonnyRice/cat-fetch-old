/* Meow!
 /'._
(° o 7
|'-'"~.  .
Uu^~C_J._."  
cute cat made by me! Inspired from this image: <https://knowyourmeme.com/photos/51151-ascii-art>  
*/
// Libs [just 5!]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"
// Thanks to Zelis for helping me figure out what was a macro

// Uppercase function because yes
char uppercase(char letter) {
    // made with the help of Eisenchan!
    return letter >= 'a' && letter <= 'z' ? letter & ~32 : letter;
}

// CPU info function
char * cpu() {
    FILE* cpu;
    char * cpu_buffer = malloc((sizeof(char) * 256));
    cpu = fopen("/proc/cpuinfo", "r");
    for (int i=0; i < 5; i++) {
        fgets(cpu_buffer, 256, (FILE *) cpu);
    }
    memmove(cpu_buffer, cpu_buffer+13, strlen(cpu_buffer));
    fclose(cpu);
    return cpu_buffer;
}

// Uptime info function
char * uptime() {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int j = 0;
    char space[] = {' '};
    FILE* uptime;
    char * uptime_buffer = malloc((sizeof(char) * 256));
    uptime = fopen("/proc/uptime", "r");
    fscanf(uptime, "%s", uptime_buffer);
    hours = (atoi(uptime_buffer)/3600); 
	minutes = (atoi(uptime_buffer) - (3600*hours))/60;
	seconds = (atoi(uptime_buffer) - (3600*hours) - (minutes*60));
    sprintf(uptime_buffer, "%12dh %dm %ds", hours, minutes, seconds);
    while (j < 1)
    {
    memmove(uptime_buffer, uptime_buffer+1, strlen(uptime_buffer));       
    if (uptime_buffer[0] != space[0]) {
        j ++;
        }
    }
    fclose(uptime);
    return uptime_buffer;
}

// Distro name function
char * distro() {
    char * distro_buffer = malloc((sizeof(char) * 256));
    FILE* distro;
    distro = fopen("/etc/os-release", "r");
    for (int i=0; i < 3; i++) {
        fgets(distro_buffer, 256, (FILE *) distro);
    }
    memmove(distro_buffer, distro_buffer+3, strlen(distro_buffer));
    distro_buffer[0] = uppercase(distro_buffer[0]);
    fclose(distro);
    return distro_buffer;
}

// Window Manager info function
char * wm() {
    return getenv("DESKTOP_SESSION");
}


// MAIN FUNCTION. oh really?
int main(int argc, char** argv) {
    size_t elements;
    Config* cfg = get_config(parse_file(get_file_content(get_config_path()), &elements), elements);
    char * cpu_fetch = cpu();
    char * uptime_fetch = uptime();
    char * distro_fetch = distro();
    char * wm_fetch = wm();
    if(cfg->awesome_icons == false)
    {
        puts("");
        printf("%s       /'._        \t%scpu: \t%s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color , cpu_fetch);
        printf("%s      (° o 7       \t%suptime: %s%s\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, uptime_fetch);
        printf("%s       |'-'\"~.  ,  \t%sdistro: %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color, distro_fetch);
        printf("%s       Uu^~(_J._.\" \t%swm: \t%s%s\n\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, wm_fetch);
	printf("\x1b[0m");
    }
    else {
        puts("");
        printf("%s      /'._        \t%s\uf2db  %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color , cpu_fetch);
        printf("%s     (° o 7       \t%s\uf017  %s%s\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, uptime_fetch);
        printf("%s      |'-'\"~.  ,  \t%s\uf085  %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color, distro_fetch);
        printf("%s      Uu^~(_J._.\" \t%s\uf2d2  %s%s\n\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, wm_fetch);
	printf("\x1b[0m");
    }
    free(cpu_fetch);
    free(uptime_fetch);
    free(distro_fetch);
    return 0;
}
