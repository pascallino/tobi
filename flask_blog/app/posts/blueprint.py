from flask import Blueprint, render_template
from models import Post

posts = Blueprint('posts', __name__, template_folder="templates")

# routes to /blog
@posts.route('/')
def post_list():
    i = 0
    postlist  = Post.query.all()
    return render_template('posts/post_list.html', postlist=postlist, i=i)

#route to specific post details
@posts.route('/<slug>')
def post_details(slug):
    postdetail = Post.query.filter(Post.slug==slug).first()
    return render_template('posts/post_detail.html', postdetail=postdetail)