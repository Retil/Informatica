from django.shortcuts import render
from django.http import HttpResponse
from noticias.models import Noticia, Autor, Seccion
from django.template import loader, Context, RequestContext
# Create your views here.

def index(request):
	latest_news_list = Noticia.objects.all()
	template = loader.get_template('noticias/index.html')
	context = RequestContext(request, {'latest.news.list', latest_news_list,})
	return HttpResponse(template.render(context))





#	return HttpResponse("Hello world. You're at the news index.")

def detail(request, Noticia_id):
	aux = Noticia.objects.get(id=Noticia_id)
	return HttpResponse("You're looking at noticia %s " %aux)

def formulario(request):
	form = NoticiaForm()
	return render(request, 'noticias/formulario.html', {'form': form})



def noticia_new(request):
	if(request.method = 'POST':
		form = NoticiaForm(request.FORM, request.FILES)
		if form.is_valid()
			form.save()
			return redirect(reverse_lazy())
	else:
		
