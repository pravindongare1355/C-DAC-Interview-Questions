package com.demo.template;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import com.demo.model.ProductPrice;
//String url = "http://price-service/api/v1.0/price/fetch?productId="+prodId;

@Service
public class PriceTemplate {

	@Autowired
	private RestTemplate restTemplate;
	
	public ProductPrice fetchPrice(final Long prodId) {
				
		
		String url = "http://localhost:8000/api/v1.0/price/fetch?productId="+prodId;
		System.out.println("Calling URL: " + url);
		
		ProductPrice productPrice = restTemplate.getForObject(url, ProductPrice.class);
		
		return productPrice;
	}
}
