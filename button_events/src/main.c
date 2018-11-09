#include <string.h>
#include <gtk/gtk.h>

GtkWidget *label_contador;

int main(int argc, char *argv[])
{
	GtkBuilder      *builder; 
	GtkWidget       *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
	label_contador = GTK_WIDGET(gtk_builder_get_object(builder, "label_contador"));
	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show(window);                
	gtk_main();

	return 0;
}

// called when window is closed
void on_window_main_destroy()
{
	gtk_main_quit();
}

/*quantidade de vezes que o usuário aperta o botao*/
int count = 0;

void button1_clicked_cb(){

	char str_count[30];
	bzero(str_count,30);

	count++;
	sprintf(str_count, "%d", count);
	gtk_label_set_text(GTK_LABEL(label_contador), str_count);

}
