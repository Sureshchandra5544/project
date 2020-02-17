#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#define  PLUGIN_DIR "plugins"
int main()
{
	char plugin_path[255];
	char *a;
	char *get_current_dir_name(void);
	DIR*  pPluginsDir = NULL;
	memset(plugin_path,0,sizeof(plugin_path));
	printf("path:(%s)\n",plugin_path);
	printf("path_using_get_current_dir_name:(%s)\n",get_current_dir_name());
	a = strcat(get_current_dir_name(),"/");
	printf("path_using_get_current_dir_name:(%s)\n",a);
		
	getcwd(plugin_path, sizeof(plugin_path));	
	printf("path_using_getcwd:(%s)\n",plugin_path);
	strcat(plugin_path,"/");
	printf("path:(%s)\n",plugin_path);
	printf("Plug_in:(%s)\n",PLUGIN_DIR);
	strcat(plugin_path,"PLUGIN_DIR");
	printf("path:(%s)\n",plugin_path);

	pPluginsDir = opendir(plugin_path);
	
	if(pPluginsDir == NULL)
	{
		switch(errno)
		{
			case ENOMEM:
				fprintf(stderr,"ERROR: out of memory: (%s)\n",pPluginsDir);
				break;
			case EACCES:
				fprintf(stderr,"ERROR: Permisson to read or write the filename is denied: (%s)\n",pPluginsDir);
				break;
			case ENOENT:
				fprintf(stderr,"ERROR: Current working directory has been unlinked(doesnot exist): (%s)\n",pPluginsDir);
				break;
			default:
				fprintf(stderr,"ERROR: openeddir failed:(%d)\n",errno);
		}
		
	}

	return 0;
}
