import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;
import javax.servlet.ServletContext;

/**
 * Application Lifecycle Listener implementation class SessionLogListener
 *
 */
@WebListener
public class SessionLogListener implements HttpSessionListener {

	/**
     * @see HttpSessionListener#sessionCreated(HttpSessionEvent)
     */
	@Override
    public void sessionCreated(HttpSessionEvent ev)  { 
		ServletContext context = ev.getSession().getServletContext();
        context.log("session created.");
    }

	/**
     * @see HttpSessionListener#sessionDestroyed(HttpSessionEvent)
     */
	@Override
    public void sessionDestroyed(HttpSessionEvent ev)  {
		ServletContext context = ev.getSession().getServletContext();
		context.log("session destroyed.");
    }
}
