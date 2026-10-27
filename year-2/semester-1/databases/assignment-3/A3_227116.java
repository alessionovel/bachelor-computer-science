package a3;

import java.sql.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Properties;
import java.util.Random;

public class A3_227116 {
	static int nTuple = 1000000;

	public static void main(String[] args) throws SQLException {
		String url = "jdbc:postgresql://sci-didattica.unitn.it/db_177";
		Properties props = new Properties();
		props.setProperty("user", "db_177");
		props.setProperty("password", "pass_177");
		props.setProperty("ssl", "false");
		Connection conn = DriverManager.getConnection(url, props);
		Statement stmt;
		PreparedStatement pstmt;
		ResultSet rs;
		String sql;
		int count;
		long start;
		int i;
		int n;
		Random random = null;
		HashSet<Integer> id = null;
		float dep;
		float depNew;
		float depOld;

		// PUNTO 1
		start = System.nanoTime();
		try {
			stmt = conn.createStatement();

			sql = "DROP TABLE IF EXISTS course";
			stmt.executeUpdate(sql);

			sql = "DROP TABLE IF EXISTS professor";
			stmt.executeUpdate(sql);

			stmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 1 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 2
		start = System.nanoTime();
		try {
			stmt = conn.createStatement();

			sql = "CREATE TABLE professor " + "(id INT not NULL, " + " name CHAR(50) not NULL, "
					+ " address CHAR(50) not NULL, " + " age INT not NULL, " + " department FLOAT not NULL, "
					+ " PRIMARY KEY (id))";
			stmt.executeUpdate(sql);

			sql = "CREATE TABLE course " + "(cid CHAR(25) not NULL, " + " cname CHAR(50) not NULL, "
					+ " credits CHAR(30) not NULL, " + " teacher INT not NULL, "
					+ " FOREIGN KEY (teacher) REFERENCES professor(id)," + " PRIMARY KEY (cid)) ";
			stmt.executeUpdate(sql);

			stmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 2 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 3
		start = System.nanoTime();
		try {
			conn.setAutoCommit(false);
			random = new Random();
			id = new HashSet<>(nTuple);
			i = 0;
			while (i < (nTuple - 1)) {
				int rand = random.nextInt(1000000000);
				if (rand != 1940 && id.add(rand)) {
					i++;
				}
			}
			id.add(1940);
			sql = "INSERT INTO professor(id,name,address,age,department) " + "VALUES(?,?,?,?,?)";
			pstmt = conn.prepareStatement(sql);
			count = 0;
			Iterator<Integer> it = id.iterator();
			n = 0;
			while (it.hasNext()) {
				n = it.next();
				pstmt.setInt(1, n);
				pstmt.setString(2, "name" + Integer.toString(n));
				pstmt.setString(3, "address" + Integer.toString(n));
				pstmt.setInt(4, n);
				pstmt.setFloat(5, n);
				pstmt.addBatch();
				count++;
				if (count % 100000 == 0 || count == id.size()) {
					pstmt.executeBatch();
				}
			}
			pstmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 3 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 4
		start = System.nanoTime();
		try {
			HashSet<Integer> cid = new HashSet<>(nTuple);
			i = 0;
			while (i < nTuple) {
				int rand = random.nextInt(1000000000);
				if (cid.add(rand)) {
					i++;
				}
			}
			sql = "INSERT INTO course(cid,cname,credits,teacher)" + "VALUES(?,?,?,?)";
			pstmt = conn.prepareStatement(sql);
			count = 0;
			Iterator<Integer> it2 = cid.iterator();
			Integer[] arrayNumbers = id.toArray(new Integer[id.size()]);

			while (it2.hasNext()) {
				n = it2.next();
				pstmt.setString(1, "name" + Integer.toString(n));
				pstmt.setString(2, "credits" + Integer.toString(n));
				pstmt.setString(3, Integer.toString(n));
				int n2 = arrayNumbers[random.nextInt(id.size())];
				pstmt.setInt(4, n2);
				pstmt.addBatch();
				count++;
				if (count % 100000 == 0 || count == cid.size()) {
					pstmt.executeBatch();
				}
			}
			pstmt.close();
			conn.setAutoCommit(true);
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 4 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 5
		start = System.nanoTime();
		try {
			stmt = conn.createStatement();
			sql = "SELECT id FROM professor";
			rs = stmt.executeQuery(sql);
			while (rs.next()) {
				System.err.println(rs.getInt(1));
			}
			rs.close();
			stmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 5 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 6
		start = System.nanoTime();
		try {
			depNew = 1973;
			depOld = 1940;
			pstmt = conn.prepareStatement("UPDATE professor SET department = ? WHERE department = ?");
			pstmt.setFloat(1, depNew);
			pstmt.setFloat(2, depOld);
			pstmt.executeUpdate();
			pstmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 6 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 7
		start = System.nanoTime();
		try {
			dep = 1973;
			pstmt = conn.prepareStatement("SELECT id, address FROM professor WHERE department = ?");
			pstmt.setFloat(1, dep);
			rs = pstmt.executeQuery();
			while (rs.next()) {
				System.err.println(rs.getInt(1) + "," + rs.getString(2));
			}
			rs.close();
			pstmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 7 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 8
		start = System.nanoTime();
		try {
			stmt = conn.createStatement();
			sql = "CREATE INDEX btreeOnDepartment ON professor USING btree (department)";
			stmt.executeUpdate(sql);
			stmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 8 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 9
		start = System.nanoTime();
		try {
			stmt = conn.createStatement();
			sql = "SELECT id FROM professor";
			rs = stmt.executeQuery(sql);
			while (rs.next()) {
				System.err.println(rs.getInt(1));
			}
			rs.close();
			stmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 9 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 10
		start = System.nanoTime();
		try {
			depNew = 1974;
			depOld = 1973;
			pstmt = conn.prepareStatement("UPDATE professor SET department = ? WHERE department = ?");
			pstmt.setFloat(1, depNew);
			pstmt.setFloat(2, depOld);
			pstmt.executeUpdate();
			pstmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 10 needs " + (System.nanoTime() - start) + " ns");

		// PUNTO 11
		start = System.nanoTime();
		try {
			dep = 1974;
			pstmt = conn.prepareStatement("SELECT id, address FROM professor WHERE department = ?");
			pstmt.setFloat(1, dep);
			rs = pstmt.executeQuery();
			while (rs.next()) {
				System.err.println(rs.getInt(1) + "," + rs.getString(2));
			}
			rs.close();
			pstmt.close();
		} catch (Exception e) {
			conn.close();
			System.out.println("err detected");
		}
		System.out.println("Step 11 needs " + (System.nanoTime() - start) + " ns");

		conn.close();

	}
}
