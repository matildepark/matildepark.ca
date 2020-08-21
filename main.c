#include <dirent.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define STR_BUF_LEN 64

char *html_head =
  "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'/>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'/>"
  "<meta name='twitter:card' content='summary_large_image' />"
  "<meta name='twitter:site' content='@matildepark_' />"
  "<meta name='twitter:creator' content='@matildepark_' />"
  "<meta name='twitter:title' content=\"%s / hello, i'm matilde park\" />"
  "<title>%s / hello, i'm matilde park</title>"
  "<link rel='stylesheet' href='/assets/style.css'/></head><body>";

char *html_header =
  "<nav><a class='site-title' href='/'>hello, i'm matilde park</a>"
  "<li><a href='/about'>about</a></li>"
  "<li><a href='/cv'>curriculum vitae</a></li>"
  "<li><a href='/projects'>projects</a></li>"
  "<li><a href='/posts'>weblog</a></li></nav>";

char *html_footer =
  "</body><footer class='border-top clearfix'><p>"
  "<a href='https://webring.xxiivv.com/#131' target='_blank' "
  "rel='noopener noreferrer'>"
  "<img src='https://webring.xxiivv.com/icon.black.svg' "
  "style='height: 1.5rem;display: inline-block;vertical-align: top;'/></a> "
  "© 2020 matilde park · articles & written content available under "
  "<a href='https://creativecommons.org/licenses/by/4.0/'>cc by 4.0</a> "
  "</p></footer></html>";

void build_page(char *name) {
  if(strcmp(name,".") == 0){ return; }
  if(strcmp(name,"..") == 0){ return; }

  printf("Building %s\n", name);

  char *filename = name;
  char filepath[STR_BUF_LEN];
  printf("%s", filename);
  printf("%s", filepath);
  snprintf(filepath, STR_BUF_LEN, "./%s", filename);
  FILE *f = fopen(filepath, "w");

  char incpath[STR_BUF_LEN];
  snprintf(incpath, STR_BUF_LEN, "./%s", filename);

  fprintf(f, html_head, (int)(strlen(filename)-4), filename);
  fputs(html_header, f);

    fprintf(f, "<main>", (int)(strlen(filename)-4), filename);
    char buffer[4096];
    FILE *fp = fopen(incpath, "r");
    if(fp == NULL){ return; }

    for (;;) {
      size_t sz = fread(buffer, 1, sizeof(buffer), fp);
      if (sz) {
        fwrite(buffer, 1, sz, f);
      } else if (feof(fp) || ferror(fp)) {
        break;
      }
    }
    fclose(fp);
    fputs("</main>", f);

  fputs(html_footer, f);

  fclose(f);
}

void processdir(char *incdir) {
  DIR *d = opendir(incdir);
  struct dirent *dir;
  if (!d) { return; }

  while ((dir = readdir(d)) != NULL) {
    build_page(dir->d_name);
  }
  closedir(d);
}

int main(void) {
  chdir("./site");
  processdir("./about");
  processdir("./cv");
  processdir("./posts");
  processdir("./projects");
  return (0);
}
