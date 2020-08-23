#include <dirent.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STR_BUF_LEN 96

char *html_head =
  "<!DOCTYPE html>\n<html lang='en'>\n\t<head>\n\t\t<meta charset='utf-8'/>\n\t\t"
  "<meta name='viewport' content='width=device-width, initial-scale=1'/>\n\t\t"
  "<meta name='twitter:card' content='summary_large_image' />\n\t\t"
  "<meta name='twitter:site' content='@matildepark_' />\n\t\t"
  "<meta name='twitter:creator' content='@matildepark_' />\n\t\t"
  "<meta name='twitter:title' content=\"%s / hello, i'm matilde park\" />\n\t\t"
  "<title>%s / hello, i'm matilde park</title>\n\t\t"
  "<link rel='stylesheet' href='../assets/style.css'/>\n\t</head>\n<body>\n";

char *html_header =
  "<nav>\n\t<a class='site-title' href='/'>hello, i'm matilde park</a>\n\t"
  "<li><a href='/about'>about</a></li>\n\t"
  "<li><a href='/cv'>curriculum vitae</a></li>\n\t"
  "<li><a href='/projects'>projects</a></li>\n\t"
  "<li><a href='/posts'>weblog</a></li></nav>\n\t";

char *html_footer =
  "</body>\n<footer class='border-top clearfix'>\n\t<p>\n\t\t"
  "<a href='https://webring.xxiivv.com/#131' target='_blank' "
  "rel='noopener noreferrer'>\n\t\t\t"
  "<img src='https://webring.xxiivv.com/icon.black.svg' "
  "style='height: 1.5rem;display: inline-block;vertical-align: top;'/>\n\t\t\t</a>\n\t\t "
  "© 2020 matilde park · articles & written content available under "
  "<a href='https://creativecommons.org/licenses/by/4.0/'>cc by 4.0</a>\n\t\t "
  "</p>\n\t</footer>\n</html>";

void build_page(char *name, char *dirname) {
  if(strcmp(name,".") == 0){ return; }
  if(strcmp(name,"..") == 0){ return; }

  printf("Building %s/%s\n", dirname, name);

  char *filename = name;
  char *folder = dirname;
  char filepath[STR_BUF_LEN];
  snprintf(filepath, STR_BUF_LEN, "site/%s/%s", folder, filename);
  FILE *f = fopen(filepath, "w");
  if (NULL == f) {
    perror("fopen failure: ");
    printf("filepath: %s\n", filepath);
    char cwd[FILENAME_MAX] = {0};
    getcwd(cwd, FILENAME_MAX);
    printf("cwd: %s\n", cwd);
    exit(1);
  }

  char incpath[STR_BUF_LEN];
  snprintf(incpath, STR_BUF_LEN, "temp/%s/%s", folder, filename);

  size_t headlen = strlen(filename);
  if (headlen > 5) { headlen -= 5; }
  char myheader[STR_BUF_LEN] = {0};
  strncpy(myheader, filename, headlen);
  if (strcmp(filename,"index.html") == 0) {
    fprintf(f, html_head, dirname, dirname);
  } else {
    fprintf(f, html_head, myheader, myheader);
  }
  fputs(html_header, f);

  fprintf(f, "<main>\n");
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

void processdir(char *incdir, char *dirname) {
  DIR *d = opendir(incdir);
  struct dirent *dir;
  if (!d) { return; }

  while ((dir = readdir(d)) != NULL) {
    build_page(dir->d_name, dirname);
  }
  closedir(d);
}

int main(void) {
  processdir("./temp/about", "about");
  processdir("./temp/cv", "cv");
  processdir("./temp/posts", "posts");
  processdir("./temp/projects", "projects");
  return (0);
}
