

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

/**
 * Servlet implementation class UploadServlet
 */
@MultipartConfig(location="C:/tmp/")
@WebServlet("/UploadServlet")
public class UploadServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UploadServlet() {
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
    @Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// アップロードされたファイルを取得
		Part part = request.getPart("file");
		
		// ファイル名はそのままで保存
		String name = this.getFileName(part);
		if(this.isValidFile(name)) {
			// part.write(getServletContext().getRealPath("/WEB-INF/data") + "/" + name);
			part.write("C:/tmp" + "/" + name);
			response.sendRedirect("upload.jsp");
		} else {
			response.getWriter().println("Invalid file is uploaded.");
		}
		
	}
	
	private String getFileName(Part part) {
		String result = null;
		
		for(String str : part.getHeader("Content-Disposition").split(";")) {
			str = str.trim();
			if(str.startsWith("filename")) {
				result = str.substring(str.indexOf("=") + 1).trim();
				result = result.replace("\"", "").replace("\\", "/");
				int pos = result.lastIndexOf("/");
				if(pos >= 0) {
					result = result.substring(pos + 1);
				}
				break;
			}
		}
		return result;
	}
	
	private boolean isValidFile(String name) {
		if(name != null) {
			String[] perms = {"gif", "jpg", "png"};
			String[] names = name.split("\\.");
			for(String perm : perms) {
				if(perm.equals(names[names.length - 1])) {
					return true;
				}
			}
		}
		return false;
	}
}
