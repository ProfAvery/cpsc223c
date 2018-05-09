#include <stdlib.h>
#include <limits.h>

#include <glib.h>
#include <glib/gprintf.h>

void usage(char *program)
{
    g_printerr("Usage: %s <file>\n", program);
    exit(EXIT_FAILURE);
}

gchar *read_contents(char *filename)
{
    gchar *contents;
    GError *error;

    if (!g_file_get_contents(filename, &contents, NULL, &error)) {
        g_printerr("%s:%s\n", filename, error->message);
        g_error_free(error);
        exit(EXIT_FAILURE);
    }

    gchar *retval = g_ascii_strdown(contents, -1);
    g_free(contents);

    return retval;
}

GString *build_split_set(void)
{
    GString *set = g_string_new(NULL);

    for (gchar c = CHAR_MIN; c < CHAR_MAX; c++) {
        if (g_ascii_ispunct(c) || g_ascii_isspace(c)) {
            g_string_append_c(set, c);
        }
    }

    return set;
}

gint compare_keys(gconstpointer a, gconstpointer b, gpointer user_data)
{
    (void) user_data;

    return g_strcmp0(a, b);
}

gpointer *new_value(gint i)
{
    gint *pi = g_malloc(sizeof(gint));
    *pi = i;
    return (gpointer) pi;
}

void destroy_value(gpointer data)
{
    g_free(data);
}

void build_tree(GTree *tree, gchar **words) {
    for (int i = 0; words[i] != NULL; i++) {
        if (words[i][0] == '\0') {
            continue;
        }

        gint *pi = g_tree_lookup(tree, words[i]);
        if (pi == NULL) {
            g_tree_insert(tree, words[i], new_value(1));
        } else {
            (*pi)++;
        }
    }
}

gboolean print_key_value(gpointer key, gpointer value, gpointer data)
{
    (void) data;

    gchar *word = key;
    gint *count = value;
    
    g_printf("%-15s\t%d\n", word, *count);

    return FALSE;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage(argv[0]);
    }

    char *contents = read_contents(argv[1]);

    GString *delimiters = build_split_set();
    gchar **words = g_strsplit_set(contents, delimiters->str, -1);

    GTree *tree = g_tree_new_full(compare_keys, NULL, NULL, destroy_value);
    build_tree(tree, words);
    g_tree_foreach(tree, print_key_value, NULL);

    g_free(contents);
    g_string_free(delimiters, TRUE);
    g_strfreev(words);
    g_tree_destroy(tree);

    return EXIT_SUCCESS;
}

